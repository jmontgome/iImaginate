#ifndef PLATFORM_INTERNAL_H
#define PLATFORM_INTERNAL_H

#include <X11/Xlib.h>

#include "../../global.h"
#include "../platform.h"

struct Platform {
    Display *display;
    Window window;
    GC gc;
    s16 screen;
};

#endif