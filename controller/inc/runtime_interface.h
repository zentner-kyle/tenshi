#ifndef INC_RUNTIME_INTERFACE_H_
#define INC_RUNTIME_INTERFACE_H_

#include <lua.h>
#include <lualib.h>

// Interpreter runtime
#include <inc/mboxlib.h>
#include <inc/runtime_entry.h>


void runtime_register(TenshiRuntimeState s);
void lua_register_all(lua_State *L);

int lua_get_device(lua_State *L);
int lua_del_device(lua_State *L);
int lua_query_dev_info(lua_State *L);



int lua_set_status_led_val(lua_State *L);
int lua_get_button_val(lua_State *L);
int lua_get_switch_val(lua_State *L);
int lua_set_led_val(lua_State *L);
int lua_get_analog_val(lua_State *L);
int lua_set_analog_val(lua_State *L);
int lua_set_grizzly_val(lua_State *L);



void setAllSmartSensorGameMode(uint8_t mode);


#endif  // INC_RUNTIME_INTERFACE_H_
