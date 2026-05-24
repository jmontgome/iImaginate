#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "global.h"
#include "input.h"

void input_processInput(XEvent event, AppState *appState) {
	if (event.type == KeyPress || 
		event.type == KeyRelease) {
		KeySym key = XLookupKeysym(&event.xkey, 0);

		if (event.type == KeyPress) {
			
		}
		else {
			if (key == XK_Escape) {
				appState->shutdownReady = 1;
			}
		}
	}
}
