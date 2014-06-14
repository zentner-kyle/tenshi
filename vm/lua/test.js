var lua = require('./build/lua/release_emscripten/lua.js');
var log = lua.Runtime.addFunction(console.log);

var code = '\n' +
'fastCallJSFunction(log, "test!")\n' +
'fastCallJSFunction(log, 1, 2, 3.1)\n' +
'\n';

var lua_state = lua.ccall('luaL_newstate', 'number');
lua.ccall('registerJS', 'number', ['number'], [lua_state]);

lua.ccall('lua_pushlightuserdata', 'number', ['number', 'number'], [lua_state, log]);
lua.ccall('lua_setglobal', 'number', ['number', 'string'], [lua_state, "log"]);

var res = lua.ccall('luaL_loadstring', 'number', ['number', 'string'], [lua_state, code]);
if (res !== 0) {
  console.log('load failed!');
}
lua.ccall('lua_pcallk', 'number',
          ['number', 'number', 'number', 'number', 'number', 'number'],
          [lua_state, 0, 0, 0, 0, 0]);
