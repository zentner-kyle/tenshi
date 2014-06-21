var lua = require('./build/lua/release_emscripten/lua.js');
var log = lua.Runtime.addFunction(console.log);

var code = '\n' +
  'i = 1\n' +
  'while true do\n' +
  '  i = i + 1\n' +
  '  fastCallJSFunction(log, i)\n' +
  'end\n' +
  '\n';

var lua_state = lua.ccall('luaL_newstate', 'number');
lua.ccall('registerJS', 'number', ['number'], [lua_state]);

lua.ccall('lua_pushlightuserdata', 'number', ['number', 'number'], [lua_state, log]);
lua.ccall('lua_setglobal', 'number', ['number', 'string'], [lua_state, "log"]);

var res = lua.ccall('luaL_loadstring', 'number', ['number', 'string'], [lua_state, code]);
if (res !== 0) {
  console.log('load failed!');
}
lua.ccall('thread_setup', 'string', ['number'], [lua_state]);
console.log(lua.ccall('thread_run_ticks', 'string', ['number', 'number'], [lua_state, 1000]));
