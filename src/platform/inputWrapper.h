#ifndef INPUTWRAPPER_H
#define INPUTWRAPPER_H

#include "platformEvent.h"
#include "../core/appState.h"

void inputWrapper_processEvent(PlatformEvent event, AppState *appState);

#endif