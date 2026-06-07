#ifndef UI_H
#define UI_H

#include "button.h"

typedef enum {
	HOME = 0,
	GAME_LIBRARY = 1
} UIStage;

typedef struct {
	Button *buttons[128];
	s16 buttonCount;
} UIElements;

void ui_clearUiElements(UIElements *elements);

#endif
