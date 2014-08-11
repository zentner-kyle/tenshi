set -x
if [ $(command -v firefox) ]; then
	# which doesn't really work on Windows, so use command -v
	FIREFOX=$(command -v firefox)
elif [ -d "$PROGRAMFILES" ] &&
     [ -x "$PROGRAMFILES/Mozilla Firefox/firefox.exe" ]; then
	# In *the future* the user might actually have a 64-bit windows
	# firefox.
	FIREFOX="$PROGRAMFILES/Mozilla Firefox/firefox.exe"
elif [ -x "C:\Program Files (x86)\Mozilla Firefox\firefox.exe" ]; then
     	# Look for the normal, 32-bit firefox in windows.
	FIREFOX="C:\Program Files (x86)\Mozilla Firefox\firefox.exe"
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

"$FIREFOX" --app angel-player/src/application.ini -jsconsole -purgecaches
