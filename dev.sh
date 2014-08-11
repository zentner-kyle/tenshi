set -x
ARGS="--app angel-player/src/application.ini -jsconsole -purgecaches"
if [ $(command -v firefox) ]; then
	# which doesn't really work on Windows, so use command -v
        firefox $ARGS
elif [ -d "$PROGRAMFILES" ] &&
     [ -x "$PROGRAMFILES/Mozilla Firefox/firefox.exe" ]; then
	# In *the future* the user might actually have a 64-bit windows
	# firefox.
	"$PROGRAMFILES/Mozilla Firefox/firefox.exe" $ARGS
elif [ -x "C:\\Program Files (x86)\\Mozilla Firefox\\firefox.exe" ]; then
     	# Look for the normal, 32-bit firefox in windows.
	"C:\\Program Files (x86)\\Mozilla Firefox\\firefox.exe" $ARGS
elif [ $(command -v open) ]; then
	# Maybe we're on OS X
        open -n -a Firefox $ARGS
else
	set +x
	echo
	echo
	echo "Error: Could not find firefox!"
	echo "Are you sure you have it installed?"
	echo
	echo "You can close this script now with ^C"
	echo
	echo
	set -x

	sleep 60
fi
