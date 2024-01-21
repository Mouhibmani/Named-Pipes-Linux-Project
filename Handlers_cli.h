#ifndef HANDLERS_CLI_H
#define HANDLERS_CLI_H

#include <signal.h>
#include <stdio.h>

void hand_reveil(int sig) {
if (sig == SIGUSR1) {
	printf("\x1b[1mSIGUSR1 signal:\x1b[0m Response has been received from the server.\n");
}
}

#endif
