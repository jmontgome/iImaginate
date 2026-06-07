#ifndef APPSTATE_H
#define APPSTATE_H

#include <X11/Xlib.h>

#include "../global.h"
#include "../ui/ui.h"

typedef enum {
	DEBUG = 0,
	RELEASE = 1
} RuntimeMode;

typedef struct {
	s8 shutdownReady;

	RuntimeMode runMode;

	s8 stageWasChanged;
	UIStage uiStage;
} AppState;

void appState_changeUiStage(AppState *appState, UIStage stage);

#endif
