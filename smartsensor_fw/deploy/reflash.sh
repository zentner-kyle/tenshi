#!/bin/bash

SCRIPT_PATH=$(dirname `which $0`)
cd $SCRIPT_PATH

if diff /etc/avrdude.conf ../../tools/avrdude.conf >/dev/null ; then
  echo
else
  echo "$(tput setaf 1)Warning: Your /etc/avrdude.conf file may not be correct.
Press Ctrl+C and then run ./tools/setup_avrdude.sh to install the correct file
or press [Enter] to continue anyways.$(tput sgr 0)"
  read
fi

set -e #exit on a non-zero exit code

python generate.py -d "$@"

set -x #echo on

python generate.py "$@" |
  sudo avrdude -c usbtiny -p attiny1634 -U flash:w:-:i

