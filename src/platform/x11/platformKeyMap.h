#ifndef PLATFORM_KEY_MAP
#define PLATFORM_KEY_MAP

#include <X11/keysym.h>

static PlatformKey platformKey_FromX11(KeySym keysym) {
	switch (keysym) {
		case XK_Escape:		return PLATFORM_KEY_ESCAPE;
		case XK_1:			return PLATFORM_KEY_1;
	}
}

#endif