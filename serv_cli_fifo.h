#ifndef SERV_CLI_FIFO_H
#define SERV_CLI_FIFO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

#define FIFO_FILE_1 "/tmp/client_to_server_fifo"
#define FIFO_FILE_2 "/tmp/server_to_client_fifo"

#define NMAX 100 // Maximum number for random numbers (adjust as needed)

// Define the structure for the question
typedef struct {
pid_t client_pid;
int number;
} Question ;

// Define the structure for the response
typedef struct {
pid_t server_pid;
int list[NMAX];
} Response;

void clearScreen() {
system("clear");
}

#endif
