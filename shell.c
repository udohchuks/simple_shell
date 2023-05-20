#include "shell.h"

/**
 * main - Entry point
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *cmd;
	char * __attribute__ ((unused)) cmd1;
	char *argv[MAX_ARGS];
	char * __attribute__ ((unused)) full_path;
	int __attribute__ ((unused)) num_arg;
	signal(SIGINT, handle_sigint);
	signal(SIGSEGV, handle_segfault);
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
		num_arg = num_args(argv);
		if (strcmp(argv[0], "exit") == 0)
		{
			_1exit(argv[1]);
		}
		if (_strcmp(argv[0], "cd") == 0)
		{
			cd(argv[1]);
			continue;
		}
		if (_strcmp(argv[0], "env") == 0)
		{
			_env();
			continue;
		}
		if (_strcmp(argv[0], "setenv") == 0)
		{
			_setenv(argv[1], argv[2]);
			continue;
		}
		if (alias_command(argv, num_arg) )
		{
			continue;
		}
		else
		{
			_exec(argv, av[0]);
			
		}
		free(cmd);
	} while (1);
	return (0);
}
