#include "appState.h"

void appState_changeUiStage(AppState *appState, UIStage stage) {
	appState->uiStage = stage;
	appState->stageWasChanged = 1;
}
