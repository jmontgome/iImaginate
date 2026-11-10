#ifndef PLATFORM_H
#define PLATFORM_H

#include "platformKey.h"
#include "platformEvent.h"

typedef struct Platform Platform;

Platform *platform_create(void);
void platform_destroy(Platform *platform);

#endif