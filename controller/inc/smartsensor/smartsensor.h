#ifndef INC_SMARTSENSOR_SMARTSENSOR_H_
#define INC_SMARTSENSOR_SMARTSENSOR_H_

#include "inc/FreeRTOS.h"
#include "inc/smartsensor/ssutil.h"
#include "inc/uart_serial_driver.h"

#define SS_NUM_SAMPLES 8  // 3 bits of resolution
#define SS_NUM_FRAMES 6
#define SS_FIRST_FRAME 1  // 1 indexed frame numbers

// Set to whatever
#define SS_MAX_SENSORS_PER_BUS 32

// Max 4 dependent on hardware
#define SS_BUS_COUNT 4


void smartsensor_init();
void ssBlockUntilActive();


portTASK_FUNCTION_PROTO(smartSensorTX, pvParameters);
portTASK_FUNCTION_PROTO(smartSensorRX, pvParameters);

#endif  // INC_SMARTSENSOR_SMARTSENSOR_H_
