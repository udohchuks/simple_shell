#include "shell.h"
void handle_sigint(int signo __attribute__((unused)))
{
	write(1, "\n", 1);
	exit(0);
  }

void handle_segfault(int signo __attribute__((unused)))
{
  /* Save the program's state and exit gracefully.*/
  exit(1);
}