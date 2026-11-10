#include "platformInternal.h"
#include "../gfx.h"

Platform *platform_create(void) {
    Platform *platform = malloc(sizeof(Platform));
    u16 ret = gfx_createWindow(platform);
    if (ret != 0) {
        printf("Failed to initialize Window\n");
        return NULL;
    }

    return platform;
}

void platform_destroy(Platform *platform) {
    gfx_cleanupAndDestroy(platform);
    free(platform);
}