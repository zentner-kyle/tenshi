#include <string.h>
#include "src/lua.h"
#include "src/lauxlib.h"
#include "src/lualib.h"
#include "src/thread.h"

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
  thread_setup(L);
  printf("%s\n", thread_run_ticks(L, 1000));
}
