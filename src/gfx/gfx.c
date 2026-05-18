#include "gfx.h"

void gfx_render(AppState *appState) {

}

void gfx_clear(AppState *appState) {
	XClearWindow(appState->display, appState->window);
}
