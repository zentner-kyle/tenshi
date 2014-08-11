#!/bin/bash -xe

export PROJECT_ROOT_DIR=`pwd`

# Set up or download tools
./tools/extract-tools.sh

# TODO(rqou): Less hacky
export PATH=$PATH:$PROJECT_ROOT_DIR/tools/arm-toolchain/bin:$PROJECT_ROOT_DIR/tools/emscripten-bin:$PROJECT_ROOT_DIR/tools/emscripten-bin/llvm/bin

if [[ -z "LLVM" ]] ; then
	export LLVM_DIR="$PROJECT_ROOT_DIR/emscripten-bin/llvm"
	export LLVM="$LLVM_DIR/bin"
	export PATH="$PATH:$PROJECT_ROOT_DIR/emscripten-bin:$LLVM"
fi

mkdir -p build/artifacts
