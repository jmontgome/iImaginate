#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>

#include "gfx/gfx.h"
#include "global.h"
#include "input.h"
#include "sys/appState.h"

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

		input_processInput(event, &appState);
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

void main_appShutdown() {
	printf("Shutting Down...\n");
}

int main(int argc, char *argv[]) {
	main_setup(argc, argv);
	
	int windowCreated = gfx_createWindow(&appState);
	if (windowCreated == -1) {
		return -1;
	}
	else {
		main_mainLoop();
	}
	
	gfx_cleanupAndDestroy();
	main_appShutdown();
	return 0;
}
