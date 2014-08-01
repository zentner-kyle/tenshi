
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Interpreter
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <ngl_vm.h>
#include <ngl_buffer.h>
#include <ngl_package.h>

// Interpreter runtime
#include <inc/mboxlib.h>
#include <inc/runtime_entry.h>

#include "inc/runtime.h"

#include "inc/button_driver.h"
#include "inc/led_driver.h"
#include "inc/task.h"
#include "inc/smartsensor/smartsensor.h"
#include "inc/smartsensor/ssutil.h"

typedef struct {
  RuntimeMessageType type;
  void *info;

  SSState *sensor;
  uint16_t sensorIndex;
  uint8_t isSensor;
} RuntimeMessage;

QueueHandle_t messageQueue = NULL;


void sensorUpdateCallback(uint16_t index, SSState *sensor);

void setLedError(int err);
int registerAllSensors(TenshiRuntimeState s);
int setupTenshiRuntime(TenshiRuntimeState *s, TenshiActorState *a,
  const char *studentCode, size_t studentCodeLen);

static portTASK_FUNCTION_PROTO(runtimeTask, pvParameters);



BaseType_t runtimeInit() {
  messageQueue = xQueueCreate(100, sizeof(RuntimeMessage));

  return xTaskCreate(runtimeTask, "Runtime", 2048, NULL, tskIDLE_PRIORITY,
                     NULL);
}

void runtimeSendRadioMsg(RuntimeMessageType type, void* info) {
  RuntimeMessage msg = {
    .type = type,
    .info = info,
    .isSensor = 0
  };
  xQueueSend(messageQueue, &msg, 0);
}

void sensorUpdateCallback(uint16_t index, SSState *sensor) {
  RuntimeMessage msg = {
    .isSensor = 1,
    .sensorIndex = index,
    .sensor = sensor,
    .type = RuntimeMessageNone,
    .info = NULL
  };
  xQueueSend(messageQueue, &msg, 0);
}

void setLedError(int err) {
  led_driver_set_mode(PATTERN_RUNTIME_ERROR);
  led_driver_set_fixed(err, 0);  // Press button 0 to view this error code
}
int registerAllSensors(TenshiRuntimeState s) {
  int ret = RUNTIME_OK, firstErr = RUNTIME_OK;
  for (uint16_t i = 0; i < numSensors; ++i) {
    SSState *sensor = sensorArr[i];
    // if (sensor->isActuator) {
      ret = MBoxCreateActuator(s, sensor->id, sizeof(sensor->id), i);
      if (ret != RUNTIME_OK && firstErr == RUNTIME_OK) firstErr = ret;
    // }
    // if (sensor->isSensor) {
      ret = MBoxCreateSensor(s, sensor->id, sizeof(sensor->id), i);
      if (ret != RUNTIME_OK && firstErr == RUNTIME_OK) firstErr = ret;
    // }
  }
  return firstErr;
}
int setupTenshiRuntime(TenshiRuntimeState *s, TenshiActorState *a,
  const char *studentCode, size_t studentCodeLen) {
  // ...
  return RUNTIME_OK;
}


static portTASK_FUNCTION_PROTO(runtimeTask, pvParameters) {
  (void) pvParameters;


  while (1) {}
  // Disable for now


  int ret = RUNTIME_OK, firstErr = RUNTIME_OK;
  RuntimeMode mode = RuntimeModeUninitialized;


  // Initialization
  registerSensorUpdateCallback(&sensorUpdateCallback);

  led_driver_set_mode(PATTERN_JUST_RED);
  led_driver_set_fixed(0b110, 0b111);


  // Wait until smart sensor enumeration finishes
  ssBlockUntilActive();

  mode = RuntimeModeDisabled;


  // TODO(cduck): Why does the linnker fail when TenshiRuntimeInit is compiled?
  TenshiRuntimeState s = TenshiRuntimeInit();

  led_driver_set_mode(PATTERN_JUST_RED);
  led_driver_set_fixed(0b101, 0b111);

  const char studentcode[] =
    "install_trap_global()\n"   // Normally this would be further down
    "input_dev = get_device('input')\n"
    "input = triggers.changed(input_dev)\n"
    "output = get_device('output')\n"
    "\n"
    "print('units.mega = ' .. units.mega)\n"
    "print('units.kilo = ' .. units.kilo)\n"
    "print('units.mili = ' .. units.mili)\n"
    "print('units.micro = ' .. units.micro)\n"
    "print('units.nano = ' .. units.nano)\n"
    "print('units.inch = ' .. units.inch)\n"
    "print('units.pound = ' .. units.pound)\n"
    "print('units.deg = ' .. units.deg)\n"
    "\n"
    "while true do\n"
    "    print('about to recv')\n"
    "    local x = input:recv()\n"
    "    if x == nil then x = 0 end\n"
    "    print('recv: ' .. x)\n"
    "    x = x + 1"
    "    print('sending using value')\n"
    "    output.value = x\n"
    "    print('sent: ' .. x)\n"
    "end";

  TenshiActorState a;

  ret = registerAllSensors(s);
  if (ret != RUNTIME_OK && firstErr == RUNTIME_OK) firstErr = ret;

  ret = LoadStudentcode(s, studentcode, strlen(studentcode), &a);
  if (ret != RUNTIME_OK && firstErr == RUNTIME_OK) firstErr = ret;

  ret = ActorSetRunnable(a, 1);
  if (ret != RUNTIME_OK && firstErr == RUNTIME_OK) firstErr = ret;

  mode = RuntimeModeTeleop;

  led_driver_set_mode(PATTERN_JUST_RED);
  led_driver_set_fixed(0b100, 0b111);

  int i = 0;
  while (1) {
    RuntimeMessage msg;
    while (xQueueReceive(messageQueue, &msg, 0) == pdTRUE) {
      if (msg.isSensor) {
        SSState *sensor = msg.sensor;

        led_driver_set_mode(PATTERN_JUST_RED);
        led_driver_set_fixed(0b011, 0b111);

        // TODO(cduck): Replace 0 with actual value
        TenshiMainStackPushFloat(s, 0);
        ret = MBoxSendSensor(s, sensor->id, sizeof(sensor->id));
        if (ret != RUNTIME_OK && firstErr == RUNTIME_OK) firstErr = ret;
      } else {
        // TODO(cduck): Handle radio input
        led_driver_set_mode(PATTERN_JUST_RED);
        led_driver_set_fixed(0b010, 0b111);
      }
    }

    ret = TenshiRunQuanta(s);
    if (ret != RUNTIME_OK && firstErr == RUNTIME_OK) firstErr = ret;

    led_driver_set_mode(PATTERN_JUST_RED);
    led_driver_set_fixed(0b1100, 0b111);

    update_info *ui_orig = MBoxGetActuatorsChanged(s);
    update_info *ui = ui_orig;
    while (ui) {
      for (int j = 0; j < ui->num_data; j++) {
        ret = MBoxRecvActuator(s, ui->id, ui->id_len);
        double x = TenshiMainStackGetFloat(s);
      }
      ui = ui->next;
    }
    MBoxFreeUpdateInfo(ui_orig);

    i++;
  }

  TenshiRuntimeDeinit(s);
}
