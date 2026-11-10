#include "inputWrapper.h"
#include "platformKey.h"

void inputWrapper_processEvent(PlatformEvent event, AppState *appState) {
    if (event.type == PLATFORM_KEY_DOWN) {
        if (event.key == PLATFORM_KEY_ESCAPE) {
            printf("Escape Key Pressed!\n");
        }
    }
}