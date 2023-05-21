#include "shell.h"

/**
 * main - Entry point
 * Return: 0 on success
 */
char *cmd = NULL;
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char * __attribute__ ((unused)) cmd1;
	char *argv[MAX_ARGS];
	char * __attribute__ ((unused)) full_path;
	int __attribute__ ((unused)) num_arg;
	signal(SIGSEGV, handle_segfault);
	do {
		if (isatty(STDIN_FILENO))
		{
			write(1, "$ ", 2);
		}
		cmd = _getline();
		signal(SIGINT, handle_sigint);
		remove_trailing_and_leading_spaces(cmd);
		if (cmd == NULL)
		{
			exit(EXIT_SUCCESS);
		}
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
		{
			continue;
		}

		tokenize(cmd, argv);
		if (_strcmp(argv[0], "exit") == 0)
		{
			free(cmd);
			_1exit(argv[1]);
		}
		if (process_command(argv) == 0)
		{
			continue;
		}
		else
		{
			_exec(argv, av[0]);
			
		}
		free(cmd);
		cmd = NULL;
	} while (1);
	return (0);
}

void handle_sigint(int signo __attribute__((unused)))
{
    write(1, "\n", 1);
    if (cmd != NULL) {
        free(cmd);
        cmd = NULL;
    }
    exit(0);
}