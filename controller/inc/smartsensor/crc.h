#ifndef INC_SMARTSENSOR_CRC_H_
#define INC_SMARTSENSOR_CRC_H_

#include <stdint.h>
#include <string.h>

uint8_t crc8(uint8_t crc, const uint8_t *data, size_t len);

#endif  // INC_SMARTSENSOR_CRC_H_
