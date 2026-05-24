#ifndef GFX_H
#define GFX_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "../global.h"
#include "../ui/ui.h"

s16 gfx_createWindow(AppState *appState);

void gfx_render(AppState *appState);
void gfx_clear(AppState *appState);

#endif
