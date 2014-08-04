
#ifndef INC_SMARTSENSOR_SSTYPE_H_
#define INC_SMARTSENSOR_SSTYPE_H_

#include "inc/smartsensor/ssutil.h"

// Sensor types
#define SENSOR_TYPE_DIGITAL 0x00
#define SENSOR_TYPE_ANALOG_IN 0x01
#define SENSOR_TYPE_GRIZZLY3 0x80
#define SENSOR_TYPE_BUZZER 0x81
#define SENSOR_TYPE_FLAG 0x82

#define CHANNEL_TYPE_MODE 0xFE


// Not exclusive.  A channel can be both.
uint8_t ss_channel_is_actuator(SSChannel *channel);
uint8_t ss_channel_is_sensor(SSChannel *channel);
uint8_t ss_channel_is_protected(SSChannel *channel);
const char * ss_channel_name(SSChannel *channel);
uint8_t ss_channel_out_length(SSChannel *channel);
uint8_t ss_channel_in_length(SSChannel *channel);


void ss_set_mode_val(SSChannel *channel, uint8_t val);  // Not set by students

void ss_set_led_val(SSChannel *channel, uint8_t val);
uint8_t ss_get_switch_val(SSChannel *channel);
void ss_set_analog_val(SSChannel *channel, double num);
double ss_get_analog_val(SSChannel *channel);
void ss_set_grizzly_val(SSChannel *channel, uint8_t mode, double speed);


#endif  // INC_SMARTSENSOR_SSTYPE_H_
