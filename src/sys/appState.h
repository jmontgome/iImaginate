#ifndef APPSTATE_H
#define APPSTATE_H

#include <X11/Xlib.h>


#include "../global.h"
#include "../ui/ui.h"

typedef enum {
	DEBUG = 0,
	RELEASE = 1
} RuntimeMode;

typedef struct {
	Button buttons[128];
} UIElements;

typedef struct {
	s8 shutdownReady;

	s16 mouseX;
	s16 mouseY;

	RuntimeMode runMode;

	Display *display;
	Window window;

	UIElements uiElements;
} AppState;

#endif
