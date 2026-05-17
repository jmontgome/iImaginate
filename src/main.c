#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>

#include "global.h"
#include "input.h"
#include "sys/sys.h"

Display *display;
Window window;

void setup(int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
		if (strMatches(argv[i], "debug") == 1 ||
			strMatches(argv[i], "--debug") == 1) {
			setDebugMode(1);
			printf("Debug Mode ON!\n");
		}
		
	}
}

int createWindow() {
	display = XOpenDisplay(NULL);
	
	if (display == NULL)
		return 1;

	int screen = DefaultScreen(display);
	
	window = XCreateSimpleWindow(
		display,
		RootWindow(display, screen),
		10, 10,
		800, 600,
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

	return 0;
}

void mainLoop() {
	XEvent event;

	while (1) {
		XNextEvent(display, &event);
		
		processInput(event);

		if (shutdownQueued()) {
			break;
		}
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

void cleanup() {
	XDestroyWindow(display, window);
	XCloseDisplay(display);
}

void shutdown() {
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
	
	cleanup();
	shutdown();
	return 0;
}
