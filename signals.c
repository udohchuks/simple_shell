#include "shell.h"

/**
* handle_sigint - handle SIGINT signal
* @signo: signal number
*/
void handle_sigint(int signo __attribute__((unused)))
{
    write(1, "\n", 1);
    exit(0);
}

/**
* handle_segfault - handle segmentation fault
* @signo: signal number
*/
void handle_segfault(int signo __attribute__((unused)))
{
    /* Save the program's state and exit gracefully.*/
    exit(1);
}
