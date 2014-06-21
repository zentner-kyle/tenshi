void thread_yield_hook(lua_State *L,
                       lua_Debug *ar);

const char *thread_setup(lua_State *L);

const char *thread_run_ticks(lua_State *L, int tick_count);
