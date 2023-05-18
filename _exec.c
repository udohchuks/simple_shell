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
	char *envp[] = { "TERM=xterm-256color", NULL };

	if (_argum[0][0] == '/')
	{
		idcheck = fork();
		if (idcheck == 0)
		{
			execve(_argum[0], _argum, envp);
		}
	}
	else
	{		
		cmd1 = which(_argum[0]);
		idcheck = fork();
		if (idcheck == 0)
		{
			execve(cmd1, _argum, envp);
		}
	}
	wait(NULL);
}
