#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "global.h"
#include "input.h"
#include "sys/sys.h"

void processInput(XEvent event) {
	if (event.type == KeyPress || 
		event.type == KeyRelease) {
		KeySym key = XLookupKeysym(&event.xkey, 0);

		if (event.type == KeyPress) {
			
		}
		else {
			if (key == XK_Escape) {
				queueShutdown();
			}
		}
	}
}
