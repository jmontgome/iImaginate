#ifndef INPUT_H
#define INPUT_H

#include <X11/Xlib.h>

#include "../global.h"
#include "../core/appState.h"

void input_processEvent(XEvent event, AppState *appState);

#endif
