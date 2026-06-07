#include "gfx.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

GC gc;
s16 screen;
Display* display;
Window window;

UIElements uiElements;

s16 gfx_createWindow() {
	display = XOpenDisplay(NULL);
	
	if (display == NULL) {
		return 1;
	}

	screen = DefaultScreen(display);

	window = XCreateSimpleWindow(
		display,
		RootWindow(display, screen),
		10, 10,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		1,
		BlackPixel(display, screen),
		WhitePixel(display, screen)
	);

	XSelectInput(display, window, ExposureMask |
		KeyPressMask |
		KeyReleaseMask |
		ButtonPressMask |
		ButtonReleaseMask |
		PointerMotionMask |
		StructureNotifyMask );
	XMapWindow(display, window);
	
	gc = XCreateGC(display, window, 0, NULL);

	return 0;
}

void gfx_nextWindowEvent(XEvent *event) {
	XNextEvent(display, event);
}

void gfx_render(AppState *appState) {
	if (appState->stageWasChanged == 1) {
		appState->stageWasChanged = 0;
		
		if (appState->uiStage == HOME) {
			printf("Home screen...\r\n");
			Button *button = ui_createButton(display,
				window, gc, 20, 20, 1, 150, 40, "Test Button");

			XDrawRectangle(display, window, gc, button->x,
				button->y, button->width, button-> height);

			XDrawString(display, window, gc, button->x + 10,
				button->y + (button->height / 2) + 5,
				button->textLabel, strLen(button->textLabel));
		}
	}
}

void gfx_clear() {
	XSetForeground(display, gc, WhitePixel(display,
		screen));

	XFillRectangle(
		display,
		window,
		gc,
		0, 0,
		WINDOW_WIDTH, WINDOW_HEIGHT
	);
}

void gfx_cleanupAndDestroy() {
	XDestroyWindow(display, window);
	XCloseDisplay(display);
}
