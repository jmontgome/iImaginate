#ifndef APPSTATE_H
#define APPSTATE_H

#include "../global.h"
#include "../ui/ui.h"

typedef enum {
	RUNTIME_DEBUG = 0,
	RUNTIME_STANDARD = 1
} RuntimeMode;

typedef struct {
	s8 shutdownReady;

	RuntimeMode runMode;

	s8 stageWasChanged;
	UIStage uiStage;
	UIElements uiElements;
} AppState;

void appState_init(AppState *appState);

void appState_changeUiStage(AppState *appState, UIStage stage);

#endif
