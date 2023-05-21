#include "shell.h"

char *command(char *cmd)
{
	alias_t aliases[100] =
	{
		{"l", "ls -CF"},
		{"la", "ls -A"},
		{"ll", "ls -alF"},
		{"ls", "ls --color=auto"},
		{NULL, NULL}
	};
}