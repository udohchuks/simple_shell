#include "shell.h"

/**
* cd - change directory
* @path: path to change to
*
* Return: 0 on success, 1 on failure
*/
void cd(char *path)
{
	char *home = _getenv("HOME");
	char *oldpwd = _getenv("OLDPWD");
	char *pwd = _getenv("PWD");
	char cwd[1024];

	if (path == NULL)
	{
		if (chdir(home) == -1)
		{
			perror("cd");
			return;
		}
		_setenv("OLDPWD", pwd);
		_setenv("pwd", home);
}
	else if (_strcmp(path, "-") == 0)
	{
		if (oldpwd != NULL)
		{
			if (chdir(oldpwd) == -1)
			{
				perror("cd");
				return;
			}
			_setenv("OLDPWD", pwd);
			_setenv("pwd", oldpwd);
		}
	}
	else
	{
		if (chdir(path) == -1)
		{
			perror("cd");
			return;
		}
		getcwd(cwd, sizeof(cwd));
		_setenv("OLDPWD", pwd);
		_setenv("pwd", cwd);
	}
}

