#include "gfx.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

s16 gfx_createWindow(AppState *appState) {
	appState->display = XOpenDisplay(NULL);
	
	if (appState->display == NULL) {
		return 1;
	}

	appState->screen = DefaultScreen(appState->display);

	appState->window = XCreateSimpleWindow(
		appState->display,
		RootWindow(appState->display, appState->screen),
		10, 10,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		1,
		BlackPixel(appState->display, appState->screen),
		WhitePixel(appState->display, appState->screen)
	);

	XSelectInput(appState->display, appState->window, ExposureMask |
		KeyPressMask |
		KeyReleaseMask |
		ButtonPressMask |
		ButtonReleaseMask |
		PointerMotionMask |
		StructureNotifyMask );
	XMapWindow(appState->display, appState->window);
	
	appState->gc = XCreateGC(appState->display, appState->window, 0, NULL);

	return 0;
}

void gfx_render(AppState *appState) {
	
}

void gfx_clear(AppState *appState) {
	XSetForeground(appState->display, appState->gc, WhitePixel(appState->display, 
		appState->screen));

	XFillRectangle(
		appState->display,
		appState->window,
		appState->gc,
		0, 0,
		WINDOW_WIDTH, WINDOW_HEIGHT
	);
}
