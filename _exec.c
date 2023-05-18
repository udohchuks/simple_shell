#include "shell.h"

/**
 * _exec - execute command
 *
 * Return: void
 */

void _exec(char **_argum, char *av)
{
	char *cmd1;
	pid_t idcheck;
	char *envp[] = { "TERM=xterm-256color", NULL };
	char err[20];

	_strcpy(err, av);

	if (_argum[0][0] == '/')
	{
		if (access(_argum[0], X_OK) == 0)
		{
			idcheck = fork();
			if (idcheck == 0)
			{
				execve(_argum[0], _argum, envp);
			}
		}
		else
		{
			perror(err);
		}
	}
	else
	{		
		cmd1 = which(_argum[0]);
		if (cmd1 == NULL)
		{
			perror(err);
		}
		idcheck = fork();
		if (idcheck == 0)
		{
			execve(cmd1, _argum, envp);
		}
	}
	wait(NULL);
}
