#ifndef GFX_H
#define GFX_H

#include "../global.h"
#include "../core/appState.h"
#include "platform.h"

u16 gfx_createWindow();

void gfx_nextWindowEvent(PlatformEvent *event);
void gfx_render(Platform *platform, AppState *appState);

void gfx_cleanupAndDestroy(Platform *platform);

#endif
