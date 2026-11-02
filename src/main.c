#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>

#include "global.h"
#include "platform/gfx.h"
#include "platform/input.h"
#include "core/appState.h"
#include "ui/ui.h"

#define FAILURE_EXIT_CODE 1
#define CLEAN_EXIT_CODE 0

AppState appState;

void main_setup(int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
		if (strMatches(argv[i], "debug") == 1 ||
			strMatches(argv[i], "--debug") == 1) {
			appState.runMode = DEBUG;
			printf("Debug Mode ON!\n");
		}
	}

	appState_changeUiStage(&appState, HOME);
}

void main_mainLoop() {
	XEvent event;

	while (1) {
		gfx_nextWindowEvent(&event);

		input_processEvent(event, &appState);
		gfx_render(&appState);

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

void main_appCleanupAndShutdown() {
	printf("Shutting Down...\n");
	ui_clearUiElements(&appState.uiElements);
	gfx_cleanupAndDestroy();
}

int main(int argc, char *argv[]) {
	main_setup(argc, argv);
	
	int windowCreated = gfx_createWindow();
	if (windowCreated == 1) {
		return FAILURE_EXIT_CODE;
	}
	main_mainLoop();
	
	main_appCleanupAndShutdown();
	return CLEAN_EXIT_CODE;
}
