#include "../global.h"
#include "sys.h"

s8 shutdownReady = 0;

void queueShutdown() {
	shutdownReady = 1;
}

s8 shutdownQueued() {
	return shutdownReady;
}
