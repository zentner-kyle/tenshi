
#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#define SENSOR_TYPE_DIGITAL 0x00
#define SENSOR_TYPE_ANALOG_IN 0x01
#define SENSOR_TYPE_BUZZER 0x81
#define SENSOR_TYPE_FLAG 0x82
// ...


// Individual Sensor data.
// todo(tobinsarah): DO THIS RIGHT!
#define HUMAN_READABLE_DESCRIPTION  'h', 'e', 'l', 'l', 'o'
#define SENSOR_TYPE SENSOR_TYPE_ANALOG_IN

#define DESCRIPTOR 0xFF, 5, HUMAN_READABLE_DESCRIPTION, 0xFF, 0xFF, 1, \
                   SENSOR_TYPE,  0xFF


#endif  // INC_CONFIG_H_
