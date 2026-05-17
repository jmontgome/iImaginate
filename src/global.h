#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>

#include "internal/types.h"
#include "internal/str.h"

s8 isDebugMode();

void setDebugMode(s8 mode);

#define DEBUG isDebugMode()

#endif
