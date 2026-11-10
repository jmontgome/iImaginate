#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "../global.h"
#include "../core/appState.h"
#include "platformKeyMap.h"
#include "../sysInput.h"

PlatformEvent sysInput_pollEvent(Platform *platform) {
	PlatformEvent platEvent;

	XEvent event;
	XNextEvent(platform->display, &event);
	if (event.type == Expose) {
		platEvent.type = PLATFORM_EVENT_REDRAW_NEEDED;
	}
	if (event.type == ConfigureNotify) {
		platEvent.type = PLATFORM_EVENT_REDRAW_NEEDED;
	}

	if (event.type == KeyPress ||
		event.type == KeyRelease) {
		if (event.type == KeyPress) {
			platEvent.type = PLATFORM_KEY_DOWN;
		}
		else {
			platEvent.type = PLATFORM_KEY_UP;
		}
		KeySym keysym = XLookupKeysym(&event.xkey, 0);
		platEvent.key = platformKey_FromX11(keysym);
	}

	return platEvent;
}
