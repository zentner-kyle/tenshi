
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/iosupport.h>

#include <ndl3.h>

#include "inc/radio.h"

#include "inc/task.h"

#include "inc/driver_glue.h"
#include "inc/uart_serial_driver.h"
#include "inc/led_driver.h"
#include "inc/xbee_framing.h"

#include "legacy_piemos_framing.h"   // NOLINT(build/include)


// Hard coded
volatile uint64_t host_addr = 0;  // Bytes reversed
#define TOTAL_PACKET_SIZE 128
#define NDL3_PACKET_SIZE (TOTAL_PACKET_SIZE-21)


void radio_send_xbee(uint8_t *data, size_t len);
void *ndAlloc(NDL3_size size, void * userdata);
void ndFree(void * to_free, void * userdata);



// Redirect printf, etc. to the radio

// con_write
// devoptab_t
// consoleInit
/*
ssize_t nocash_write(struct _reent *r, int fd, const char *ptr, size_t len) {
  nocashWrite(ptr, len);
  return len;
}

ssize_t con_write(struct _reent *r, int fd, const char *ptr, size_t len) {
}

static const devoptab_t dotab_stdout = {
  "con",
  0,
  NULL,
  NULL,
  con_write,
  NULL,
  NULL,
  NULL
};


void consoleInit() {
  static uint8_t firstConsoleInit = true;

  if (firstConsoleInit) {
    devoptab_list[STD_OUT] = &dotab_stdout;
    devoptab_list[STD_ERR] = &dotab_stdout;
    setvbuf(stdout, NULL , _IONBF, 0);
    setvbuf(stderr, NULL , _IONBF, 0);
    firstConsoleInit = false;
  }
}
*/


static portTASK_FUNCTION_PROTO(radioNewTask, pvParameters);

BaseType_t radioInit() {
  radio_driver_init();

  return xTaskCreate(radioNewTask, "Radio", 1024, NULL, tskIDLE_PRIORITY,
                     NULL);
}

// TODO(cduck): Move this to uart_serial_driver.c and make it work
int radio_uart_serial_send_and_finish_data(const uint8_t *data, size_t len) {
  // TODO(rqou): Asynchronous?
  // TODO(rqou): Error handling
  void *txn = uart_serial_send_data(radio_driver, data, len);
  while ((uart_serial_send_status(radio_driver, txn) !=
      UART_SERIAL_SEND_DONE) &&
      (uart_serial_send_status(radio_driver, txn) !=
        UART_SERIAL_SEND_ERROR)) {}
  return uart_serial_send_finish(radio_driver, txn);
}

void radio_send_xbee(uint8_t *data, size_t len) {
  if (len > NDL3_PACKET_SIZE) return;

  // TODO(cduck): Do Robert's TODOs below

  // TODO(rqou): Hack
  uint8_t txbuf[TOTAL_PACKET_SIZE];

  // Create magic struct
  xbee_api_packet *packetOut = (xbee_api_packet *)(txbuf);
  packetOut->xbee_api_magic = XBEE_MAGIC;
  int payloadLen = sizeof(xbee_tx64_header) + len+1;
  packetOut->length = __REV16(payloadLen);
  packetOut->payload.tx64.xbee_api_type = XBEE_API_TYPE_TX64;
  packetOut->payload.tx64.frameId = 0;
  packetOut->payload.tx64.xbee_dest_addr = host_addr;
  packetOut->payload.tx64.options = 0;

  packetOut->payload.tx64.data[0] = NDL3_IDENT;
  memcpy(&(packetOut->payload.tx64.data[1]), data, len);

  xbee_fill_checksum(packetOut);

  // TODO(rqou): Asynchronous?
  // TODO(rqou): Abstract away the +4 properly
  // TODO(rqou): Error handling
  void *txn = uart_serial_send_data(radio_driver, txbuf, payloadLen + 4);
  while (!uart_serial_send_finish(radio_driver, txn)) {}
}
void *ndAlloc(NDL3_size size, void * userdata) {
  (void) userdata;
  void *ret = pvPortMalloc(size);
  while (!ret) {}
  return ret;
}
void ndFree(void * to_free, void * userdata) {
  (void) userdata;
  vPortFree(to_free);
}



static portTASK_FUNCTION_PROTO(radioNewTask, pvParameters) {
  (void) pvParameters;

  NDL3Net * target = NDL3_new(ndAlloc, ndFree, NULL);
  NDL3_open(target, NDL3_UBJSON_PORT);
  NDL3_open(target, NDL3_STRING_PORT);
  NDL3_open(target, NDL3_CODE_PORT);
  char * in_msg = "This string came from the Big Board:  ";
  NDL3_send(target, 1, in_msg, 1 + strlen(in_msg));
  char * recvMsg = NULL;

  const uint8_t prefixLen = 1;
  xbee_api_packet *recXbeePacket;
  xbee_rx64_header *recXbeeHeader;
  uint8_t buffer[NDL3_PACKET_SIZE];
  NDL3_size popSize = 0;
  NDL3_size recvSize = 0;
  NDL3_size uartRecvSize = 0;
  int a = 1;

  portTickType time = xTaskGetTickCount();
  portTickType lastTime = time;

  while (1) {
    recvMsg = NULL;
    recvSize = 0;
    NDL3_recv(target, NDL3_UBJSON_PORT, (void **) &recvMsg, &recvSize);
    // Do stuff with recieved message
    if (recvMsg && recvSize >= 1) {
      led_driver_set_mode(PATTERN_JUST_RED);
      led_driver_set_fixed(recvMsg[3]-1, 0b111);
    }
    vPortFree(recvMsg);

    recvMsg = NULL;
    recvSize = 0;
    NDL3_recv(target, NDL3_STRING_PORT, (void **) &recvMsg, &recvSize);
    // Do stuff with recieved message

    vPortFree(recvMsg);

    recvMsg = NULL;
    recvSize = 0;
    NDL3_recv(target, NDL3_CODE_PORT, (void **) &recvMsg, &recvSize);
    // Do stuff with recieved message

    vPortFree(recvMsg);


    if (a % 500 == 0 && host_addr != 0) {
      // Send message
      in_msg[strlen(in_msg) - 1] = (char) (a/1000%10) + '0';
      NDL3_send(target, NDL3_STRING_PORT, in_msg, 1 + strlen(in_msg));
    } else {
      a = 0;
    }

    recXbeePacket = (xbee_api_packet*)uart_serial_receive_packet(radio_driver,
      &uartRecvSize, 0);
    if (recXbeePacket) {
      recXbeeHeader = &(recXbeePacket->payload);
      if (recXbeeHeader->xbee_api_type == XBEE_API_TYPE_RX64) {
        host_addr = recXbeeHeader->xbee_src_addr;
        if (uartRecvSize >= prefixLen && recXbeeHeader->data[0] == NDL3_IDENT) {
          NDL3_L2_push(target, (uint8_t*)recXbeeHeader->data+1,
            recXbeePacket->length-sizeof(xbee_rx64_header)-prefixLen);
        }
      }
      vPortFree(recXbeePacket);
    }

    popSize = 0;
    NDL3_L2_pop(target, buffer, NDL3_PACKET_SIZE, &popSize);
    if (popSize > 0) {
      radio_send_xbee(buffer, popSize);
    }

    time = xTaskGetTickCount();
    NDL3_elapse_time(target, time-lastTime);
    lastTime = time;

    a++;
    // vTaskDelay(200 / portTICK_RATE_MS);
  }
}
