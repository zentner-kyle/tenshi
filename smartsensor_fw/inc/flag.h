
#ifndef INC_FLAG_H_
#define INC_FLAG_H_

#include "inc/smartsensor/common.h"

#define BLUE_LED IN2
#define YELLOW_LED IN3

#define FLAG_MODE_1 0x80
// ...

// Public functions called from main.c
void initFlag();
void activeFlagRec(uint8_t *data, uint8_t len, uint8_t inband);
void activeFlagSend(uint8_t *outData, uint8_t *outLen, uint8_t *inband);

#endif  // INC_FLAG_H_
