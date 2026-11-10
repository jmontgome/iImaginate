#include "../gfx.h"
#include "platformInternal.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

u16 gfx_createWindow(Platform *platform) {
	platform->display = XOpenDisplay(NULL);

	if (platform->display == NULL) {
		return 1;
	}

	platform->screen = DefaultScreen(platform->display);

	platform->window = XCreateSimpleWindow(
		platform->display,
		RootWindow(platform->display, platform->screen),
		10, 10,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		1,
		BlackPixel(platform->display, platform->screen),
		WhitePixel(platform->display, platform->screen)
	);

	XSelectInput(platform->display, platform->window, ExposureMask |
		KeyPressMask |
		KeyReleaseMask |
		ButtonPressMask |
		ButtonReleaseMask |
		PointerMotionMask |
		StructureNotifyMask );
	XMapWindow(platform->display, platform->window);

	platform->gc = XCreateGC(platform->display, platform->window, 0, NULL);

	XSetForeground(platform->display, platform->gc, 
		BlackPixel(platform->display, platform->screen));
	return 0;
}

void gfx_render(Platform *platform, AppState *appState,
	PlatformEvent event) {
	//Create objects for new screen

	u16 internalRedraw = 0;
	if (appState->stageWasChanged == 1) {
		appState->stageWasChanged = 0;
		//Clean current UI Elements
		ui_clearUiElements(&appState->uiElements);

		//Figure out what stage we're on and make its UI elements
		if (appState->uiStage == HOME) {
			printf("Home screen...\n");
			Button *button = ui_createButton(20, 20, 1, 150, 40, "Welcome!");

			appState->uiElements.buttons[0] = button;
			appState->uiElements.buttonCount = 1;
		}

		if (appState-> uiStage == GAME_LIBRARY) {
			printf("Game library...\n");
			Button *button = ui_createButton(20, 20, 1, 150, 40, "Play a Game!");

			appState->uiElements.buttons[0] = button;
			appState->uiElements.buttonCount = 1;
		}
		internalRedraw = 1;
	}

	//Render the objects needed.
	if (event.type == PLATFORM_EVENT_REDRAW_NEEDED ||
		internalRedraw == 1) {
		XClearWindow(platform->display, platform->window);

		for (int i = 0; i < appState->uiElements.buttonCount; i++) {
			if (appState->uiElements.buttons[i] == NULL) {
				printf("Button No %d appears to be null or corrupted...", i);
				continue;
			}

			Button *button = appState->uiElements.buttons[i];
			XDrawRectangle(platform->display, platform->window, 
				platform->gc,
				button->x, button->y, button->width,
				button->height);
			XDrawString(platform->display, platform->window, platform->gc,
				button->x + 10, button->y + (button-> height / 2) + 5,
				button->textLabel, strLen(button->textLabel));
		}
	}
}

void gfx_cleanupAndDestroy(Platform *platform) {
	XDestroyWindow(platform->display, platform->window);
	XCloseDisplay(platform->display);
}
