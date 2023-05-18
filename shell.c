#include "shell.h"
#include <sys/wait.h>

/**
 * main - Entry point
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *cmd;
	char * __attribute__ ((unused)) cmd1;
	char *argv[MAX_ARGS];
	char *argv_alias[MAX_ARGS] __attribute__ ((unused));
	int  __attribute__ ((unused)) alias;
	char * __attribute__ ((unused)) full_path;
	int __attribute__ ((unused)) num_arg;

	do {
		if (isatty(STDIN_FILENO))
		{
			write(1, "$ ", 2);
		}
		cmd = _getline();
		remove_trailing_spaces(cmd);
		if (cmd == NULL)
		{
			exit(EXIT_SUCCESS);
		}
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
		{
			continue;
		}

		tokenize(cmd, argv);
		_exec(argv, av[0]);
		num_arg = num_args(argv);
			
		alias = alias_command(argv, num_arg);
		free(cmd);
	} while (1);
	return (0);
}
