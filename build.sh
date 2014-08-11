#!/bin/bash -xe

. tools/begin-build.sh

# Run linters
linter_status=0
for tool in cpplint pep8 jshint csslint
do
  ./tools/run-style-tool.py $tool 2>&1 | tee build/${tool}.txt
  linter_status=$[${linter_status} || ${PIPESTATUS[0]}]
done

if [ $linter_status != 0 ] ; then
  exit $linter_status
fi

WAF_ARGS="$@"
if [ -z "$WAF_ARGS" ]; then
  WAF_ARGS="configure build"
fi

./waf $WAF_ARGS

./angel-player/build.sh

# Run unit test for Angel Player
# TODO(rqou): Fix the fact that this has to be run at the end of the build
# process and can't be run at the beginning.
./angel-player/run-tests.py
