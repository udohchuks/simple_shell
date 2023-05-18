#include "shell.h"

/**
 * _exec - execute command
 *
 * Return: void
 */

void _exec(char **_argum)
{
	char *cmd1;
	pid_t idcheck;
		
	cmd1 = which(_argum[0]);
	idcheck = fork();
	if (idcheck == 0)
	{
		execve(cmd1, _argum, NULL);
	}
	wait(NULL);
}
