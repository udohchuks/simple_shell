#include "shell.h"

/**
* _exec - execute command
* @_argum: array of arguments
* @av: name of program
*/
void _exec(char **_argum, char *av)
{
	char *cmd1, err[20];
	pid_t idcheck;
	char *envp[] = {"TERM=xterm-256color", NULL};

	_strcpy(err, av);
	ex_code = 0;
	if (_argum[0][0] == '/')
	{
		if (access(_argum[0], X_OK) == 0)
		{
			idcheck = fork();
			if (idcheck == 0)
				_execve(_argum[0], _argum, envp);
		}
		else
		{
			_perror(err);
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
				_perror(err);
				return;
			}
		}
		else
			cmd1 = _argum[0];
		idcheck = fork();
		if (idcheck == 0)
			_execve(cmd1, _argum, envp);
	free(cmd1);
	}
	wait(NULL);
}

/**
 * _execve - runs error code and exec
 * @c: command prompt
 * @p: arguments to command
 * @r: environment variable
 */

void _execve(char *c, char **p, char **r)
{
	ex_code = 0;
	execve(c, p, r);
	ex_code = 1;
}

/**
 * _perror - printing error and checking exit code
 * @err: error string
 */

void _perror(char *err)
{
	ex_code = 127;
	perror(err);
}

