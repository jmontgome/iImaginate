#include "button.h"

Button* ui_createButton(Display *display,
	Window window,
	GC gc,
	s16 x,
	s16 y,
	s16 z,
	s16 width,
	s16 height,
	const char *text) {
	Button *button = malloc(sizeof(Button));
	if (!button)
		return NULL;

	button->x = x;
	button->y = y;
	button->z = z;
	button->width = width;
	button->height = height;

	//Make my own str.c method for this for dynamic lengthed strings and fixed lengths
	snprintf(button->textLabel, sizeof(button->textLabel), "%s", text);

	return button;
}
