#include <string.h>
#include "src/lua.h"
#include "src/lauxlib.h"
#include "src/lualib.h"

void yield_hook(lua_State *L, lua_Debug *ar) {
  (void) ar;
  printf("yielding\n");
  lua_yield(L, 0);
}

int main (int argc, char **argv) {
  lua_State *L = luaL_newstate();
  const char *s =
  "i = 1\n"
  "while true do\n"
  "  i = i + 1\n"
  "  print(i)\n"
  "end\n"
  "\n";
  luaL_openlibs(L);  /* open libraries */
  printf("code = \n%s\n", s);
  int status = 0;
  status = luaL_loadstring(L, s);
  if (status != 0) {
    printf("ERROR in load\n");
  }
  lua_sethook(L, &yield_hook, LUA_MASKCOUNT, 64);
  do {
    status = lua_resume(L, 0, 0);
    printf("yielded\n");
  } while (status == LUA_YIELD);
}
