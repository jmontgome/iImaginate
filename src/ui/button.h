#ifndef BUTTON_H
#define BUTTON_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "../global.h"

typedef struct {
	s16 x;
	s16 y;
	s16 z;
	s16 width;
	s16 height;
	char textLabel[64];
} Button;

Button *ui_createButton(s16 x,
	s16 y,
	s16 z,
	s16 width,
	s16 height,
	const char *text);

#endif
