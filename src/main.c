#include "platform/gfx.h"
#include "platform/inputWrapper.h"
#include "platform/platform.h"
#include "platform/sysInput.h"
#include "core/appState.h"
#include "ui/ui.h"

#define FAILURE_EXIT_CODE 1
#define CLEAN_EXIT_CODE 0

AppState appState;

void main_setup(int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
		if (strMatches(argv[i], "debug") == 1 ||
			strMatches(argv[i], "--debug") == 1) {
			appState.runMode = RUNTIME_DEBUG;
			printf("Debug Mode ON!\n");
		}
	}

	appState_changeUiStage(&appState, HOME);
}

void main_mainLoop(Platform *platform) {
	PlatformEvent event;

	while (1) {
		event = sysInput_pollEvent(platform);
		inputWrapper_processEvent(event, &appState);
		gfx_render(platform, &appState, event);

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

void main_appCleanupAndShutdown(Platform *platform) {
	printf("Shutting Down...\n");
	ui_clearUiElements(&appState.uiElements);
	platform_destroy(platform);
}

int main(int argc, char *argv[]) {
	appState_init(&appState);
	main_setup(argc, argv);

	Platform *platform = platform_create();
	if (platform == NULL) {
		printf("Failed to initialize Platform\r\n");
		return FAILURE_EXIT_CODE;
	}

	main_mainLoop(platform);
	
	main_appCleanupAndShutdown(platform);
	return CLEAN_EXIT_CODE;
}
