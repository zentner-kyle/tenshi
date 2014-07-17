#include "inc/smartsensor/crc.h"

// Functions in this file adapted from
// http://stackoverflow.com/a/15171925

#define POLY 0xD5  // CRC8 polynomial: x^8 + x^7 + x^6 + x^4 + x^2 + 1

uint8_t crc8(uint8_t crc, uint8_t *data, size_t len) {
  uint8_t *end;

  if (len == 0)
    return crc;
  crc ^= 0xff;
  end = data + len;
  do {
    crc ^= *data++;
    crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
    crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
    crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
    crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
    crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
    crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
    crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
    crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
  } while (data < end);
  return crc ^ 0xff;
}
