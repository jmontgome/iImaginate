#include "global.h"

s8 debug = 0;

s8 isDebugMode() {
	return debug;
}

void setDebugMode(s8 mode) {
	if (mode == 0 || mode == 1) {
		debug = mode;
	}
}
