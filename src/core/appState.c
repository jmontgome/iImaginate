#include "appState.h"

void appState_init(AppState *appState) {
	appState->shutdownReady = 0;
	appState->runMode = RUNTIME_STANDARD;
	appState->stageWasChanged = 0;
	appState->uiStage = HOME;
}

void appState_changeUiStage(AppState *appState, UIStage stage) {
	appState->uiStage = stage;
	appState->stageWasChanged = 1;
}
