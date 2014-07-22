
# Functions in this file adapted from
# http://stackoverflow.com/a/15171925

POLY = 0xD5  # CRC8 polynomial: x^8 + x^7 + x^6 + x^4 + x^2 + 1

def crc8(crc, data):
  crc ^= 0xff;
  for val in data:
    crc ^= val;
    crc = (crc >> 1) ^ POLY if crc & 1 else crc >> 1;
    crc = (crc >> 1) ^ POLY if crc & 1 else crc >> 1;
    crc = (crc >> 1) ^ POLY if crc & 1 else crc >> 1;
    crc = (crc >> 1) ^ POLY if crc & 1 else crc >> 1;
    crc = (crc >> 1) ^ POLY if crc & 1 else crc >> 1;
    crc = (crc >> 1) ^ POLY if crc & 1 else crc >> 1;
    crc = (crc >> 1) ^ POLY if crc & 1 else crc >> 1;
    crc = (crc >> 1) ^ POLY if crc & 1 else crc >> 1;
  return crc ^ 0xff;
