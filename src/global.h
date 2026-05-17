#ifndef GLOBAL_H
#define GLOBAL_H

#include "internal/types.h"

s8 isDebugMode();

void setDebugMode(s8 mode);

#define DEBUG isDebugMode()

#endif
