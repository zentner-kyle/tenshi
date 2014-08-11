#!/bin/bash -xe

. tools/begin-build.sh

ARGS="$@"
if [ -z "$ARGS" ]; then
  ARGS='--emcc-only
        configure
        build_network/release_emscripten
        build_lua/release_emscripten
        build_vm/release_emscripten'
fi

./waf $ARGS

./angel-player/build.sh
