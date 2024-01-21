#ifndef HANDLERS_SERV_H
#define HANDLERS_SERV_H

#include <signal.h>
#include <stdio.h>
#include "serv_cli_fifo.h"

void handler_reveil(int sig) {
if (sig == SIGUSR1) {
	printf("\x1b[1mSIGUSR1 signal:\x1b[0m Response has been received by the client.\n");
}
}

void fin_server(int sig) {
if (sig != SIGUSR1) {
	printf("\n\x1b[1mAnother signal has been received:\x1b[0m Server is down");
	unlink(FIFO_FILE_1);
	unlink(FIFO_FILE_2);
	exit(0);
}
}

#endif
