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

	XSetForeground(display, gc, BlackPixel(display, screen));
	return 0;
}

void gfx_nextWindowEvent(XEvent *event) {
	XNextEvent(display, event);
}

void gfx_render(AppState *appState) {
	//Create objects for new screen
	if (appState->stageWasChanged == 1) {
		appState->stageWasChanged = 0;
		//Clean current UI Elements
		gfx_clear();

		//Figure out what stage we're on and make its UI elements
		if (appState->uiStage == HOME) {
			printf("Home screen...\r\n");
			Button *button = ui_createButton(20, 20, 1, 150, 40, "Welcome!");

			uiElements.buttons[0] = button;
			uiElements.buttonCount = 1;
		}

		if (appState-> uiStage == GAME_LIBRARY) {
			printf("Game library...\r\n");
			Button *button = ui_createButton(20, 20, 1, 150, 40, "Play a Game!");

			uiElements.buttons[0] = button;
			uiElements.buttonCount = 1;
		}
	}

	//Render the objects needed.
	for (int i = 0; i < uiElements.buttonCount; i++) {
		if (uiElements.buttons[i] == NULL) {
			printf("Button No %d appears to be null or corrupted...", i);
			continue;
		}
		Button *button = uiElements.buttons[i];
		XDrawRectangle(display, window, gc,
			button->x, button->y, button->width,
			button->height);
		XDrawString(display, window, gc,
			button->x + 10, button->y + (button->height / 2) + 5,
			button->textLabel, strLen(button->textLabel));
	}
}

void gfx_clear() {
	ui_clearUiElements(&uiElements);
	XClearWindow(display, window);
}

void gfx_cleanupAndDestroy() {
	XDestroyWindow(display, window);
	XCloseDisplay(display);
}
