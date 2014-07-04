// Licensed to Pioneers in Engineering under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Pioneers in Engineering licenses
// this file to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
//  with the License.  You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License

#ifndef INC_RUNTIME_ENTRY_H_
#define INC_RUNTIME_ENTRY_H_

#include <stdlib.h>

typedef struct _TenshiRuntimeState* TenshiRuntimeState;

#include "inc/actor_sched.h"

extern TenshiRuntimeState TenshiRuntimeInit(void);
extern void TenshiRuntimeDeinit(TenshiRuntimeState s);

// Returns the same values as lua_load. Automatically creates a new actor for
// the loaded code.
extern int LoadStudentcode(TenshiRuntimeState s, const char *data, size_t len,
  TenshiActorState *actor_state);

#endif  // INC_RUNTIME_ENTRY_H_
