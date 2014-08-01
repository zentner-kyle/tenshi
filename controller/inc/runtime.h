
#ifndef INC_RUNTIME_H_
#define INC_RUNTIME_H_

#include "inc/FreeRTOS.h"

#define RUNTIME_OK LUA_OK

typedef enum {
  RuntimeMessageNone = 0,
  RuntimeMessageNewCode,
  RuntimeMessageRemoteValue,
  RuntimeMessageGameMode,
} RuntimeMessageType;

typedef enum {
  RuntimeModeUninitialized = 0,
  RuntimeModeDisabled      = 1,
  RuntimeModeAutonomous    = 2,
  RuntimeModeTeleop        = 3,
} RuntimeMode;


BaseType_t runtimeInit();
/*
void runtimeSendRadioMsg(RuntimeMessageType type, void* info);
*/

#endif  // INC_RUNTIME_H_
