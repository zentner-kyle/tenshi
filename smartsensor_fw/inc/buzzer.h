
#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "inc/smartsensor/common.h"

// Public functions called from main.c
void initBuzzer();
void activeBuzzerRec(uint8_t *data, uint8_t len, uint8_t inband);
void activeBuzzerSend(uint8_t *outData, uint8_t *outLen, uint8_t *inband);

#endif  // INC_BUZZER_H_
