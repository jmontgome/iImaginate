#include <stdlib.h>

#include "ui.h"

void ui_clearUiElements(UIElements *ui) {
	for (int i = 0; i < ui->buttonCount; i++) {
		free(ui->buttons[i]);
	}
}
