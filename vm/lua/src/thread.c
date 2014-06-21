#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

const static int thread_ops_per_tick = 128;

static lua_Hook thread_old_hook = NULL;

void thread_yield_hook(lua_State *L,
                       lua_Debug *ar) {
  if (ar->event & LUA_HOOKCOUNT) {
    lua_yield(L, 0);
  } else if (thread_old_hook != NULL) {
    (*thread_old_hook)(L, ar);
  }
}

const char *thread_setup(lua_State *L) {
  thread_old_hook = lua_gethook(L);
  lua_sethook(L, &thread_yield_hook, lua_gethookcount(L) | LUA_MASKCOUNT, 
      thread_ops_per_tick);
  return NULL;
}

const char *thread_run_ticks(lua_State *L, int tick_count) {
  int status = 0;
  int ticks_so_far = 0;
  do {
    status = lua_resume(L, 0, 0);
    ticks_so_far += 1;
  } while (ticks_so_far < tick_count && status == LUA_YIELD);
  if (status == LUA_OK) {
    return "Done";
  } else if (status == LUA_YIELD) {
    return NULL;
  } else {
    return "Error";
  }
}
