#!/bin/bash -xe

. tools/begin-build.sh

# Run linters
linter_status=0
for tool in jshint csslint
do
  ./tools/run-style-tool.py $tool 2>&1 | tee build/${tool}.txt
  linter_status=$[${linter_status} || ${PIPESTATUS[0]}]
done

# To make sure that xulrunner is extracted to run the tests.
./angel-player/build.sh

# Run tests
./angel-player/run-tests.py
