#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>

#include "gfx/gfx.h"
#include "global.h"
#include "input.h"

AppState appState;

void setup(int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
		if (strMatches(argv[i], "debug") == 1 ||
			strMatches(argv[i], "--debug") == 1) {
			appState.runMode = DEBUG;
			printf("Debug Mode ON!\n");
		}
		
	}
}

int createWindow() {
	appState.display = XOpenDisplay(NULL);
	
	if (appState.display == NULL)
		return 1;

	int screen = DefaultScreen(appState.display);
	
	appState.window = XCreateSimpleWindow(
		appState.display,
		RootWindow(appState.display, screen),
		10, 10,
		800, 600,
		1,
		BlackPixel(appState.display, screen),
		WhitePixel(appState.display, screen)
	);

	XSelectInput(appState.display, appState.window, ExposureMask |
		KeyPressMask |
		KeyReleaseMask |
		ButtonPressMask |
		ButtonReleaseMask |
		PointerMotionMask |
		StructureNotifyMask );
	XMapWindow(appState.display, appState.window);

	return 0;
}

void mainLoop() {
	XEvent event;

	while (1) {
		XNextEvent(appState.display, &event);
		
		gfx_clear(&appState);
		gfx_render(&appState);

		processInput(event, &appState);

		if (appState.shutdownReady) break;
		/*
		Exit logic is as follows:
		-Wait for exit command
		-Send Machine shutdown message
		
		On machine restart:
		-Kick off this program

		When attempting to tab out:
		-Force focus back onto this application
		*/
	}
}

void appCleanup() {
	XDestroyWindow(appState.display, appState.window);
	XCloseDisplay(appState.display);
}

void appShutdown() {
	printf("Shutting Down...\n");
}

int main(int argc, char *argv[]) {
	setup(argc, argv);
	
	int windowCreated = createWindow();
	if (windowCreated == -1) {
		return -1;
	}
	else {
		mainLoop();
	}
	
	appCleanup();
	appShutdown();
	return 0;
}
