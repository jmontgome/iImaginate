#ifndef PLATFORM_EVENT_TYPE
#define PLATFORM_EVENT_TYPE

#include "platformKey.h"

typedef enum {
    PLATFORM_EVENT_NONE,
    PLATFORM_EVENT_QUIT,
    PLATFORM_EVENT_REDRAW_NEEDED,
    PLATFORM_KEY_DOWN,
    PLATFORM_KEY_UP
} PlatformEventType;

typedef struct {
    PlatformEventType type;
    PlatformKey key;
} PlatformEvent;

#endif