#ifndef GFX_H
#define GFX_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "../global.h"
#include "../sys/appState.h"
#include "../ui/ui.h"

s16 gfx_createWindow();

void gfx_nextWindowEvent(XEvent *event);
void gfx_render(AppState *appState);
void gfx_clear();

void gfx_cleanupAndDestroy();

#endif
