#include "shell.h"

/**
* _exec - execute command
* @_argum: array of arguments
* @av: name of program
*/
void _exec(char **_argum, char *av)
{
	char *cmd1;
	pid_t idcheck;
	char *envp[] = {"TERM=xterm-256color", NULL};
	char err[1024];
	int len;

	_strcpy(err, av);
	_strcat(err, ": 1: ");
	_strcat(err, _argum[0]);
	_strcat(err, ": not found\n");
	if (_argum[0][0] == '/')
	{
		if (access(_argum[0], X_OK) == 0)
		{
			idcheck = fork();
			if (idcheck == 0)
				execve(_argum[0], _argum, envp);
		}
		else
		{
			len = _strlen(err);
			write(STDERR_FILENO, err, len);
			return;
		}
	}
	else
	{
		if (_argum[0][0] != '.')
		{
			cmd1 = which(_argum[0]);
			if (cmd1 == NULL)
			{
				len = _strlen(err);
				write(STDERR_FILENO, err, len);
				return;
			}
			free(cmd1);
		}
		else
			cmd1 = _argum[0];
		idcheck = fork();
		if (idcheck == 0)
			execve(cmd1, _argum, envp);
	}
	wait(NULL);
}
