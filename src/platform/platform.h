#ifndef PLATFORM_H
#define PLATFORM_H

typedef enum {
    PLATFORM_EVENT_NONE,
    PLATFORM_EVENT_QUIT,
    PLATFORM_EVENT_REDRAW_NEEDED,
    PLATFORM_KEY_DOWN,
    PLATFORM_KEY_UP
} PlatformEventType;

typedef enum {
    PLATFORM_KEY_UNKNOWN,
    PLATFORM_KEY_ESCAPE,
    PLATFORM_KEY_1,
    PLATFORM_KEY_2
} PlatformKey;

typedef struct Platform Platform;
typedef struct PlatformEvent PlatformEvent;

#endif