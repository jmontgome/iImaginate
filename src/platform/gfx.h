#ifndef GFX_H
#define GFX_H

#include "../global.h"
#include "../core/appState.h"
#include "platform.h"

u16 gfx_createWindow(Platform *platform);

void gfx_render(Platform *platform, AppState *appState,
    PlatformEvent event);

void gfx_cleanupAndDestroy(Platform *platform);

#endif
