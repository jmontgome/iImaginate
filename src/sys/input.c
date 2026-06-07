#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "../global.h"
#include "../sys/appState.h"
#include "input.h"

void input_processInput(XEvent event, AppState *appState) {
	if (event.type == KeyPress ||
		event.type == KeyRelease) {
		KeySym key = XLookupKeysym(&event.xkey, 0);

		if (event.type == KeyPress) {
			
		}
		else {
			if (key == XK_Escape) {
				if (appState->runMode == DEBUG) {
					appState->shutdownReady = 1;
				}
				else {
					//For now, we will let this shutdown the app
					//	because the app will run on a device
					//	without a keyboard.
					appState->shutdownReady = 1;
				}
			}
		}
	}
}
