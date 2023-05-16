#include "shell.h"
/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	char *cmd;
	size_t nread, n = 0;

	do {
		if (isatty(STDIN_FILENO))
		{
			write(1, "$ ", 2);
		}
		cmd = _getline();
		if (cmd == NULL)
		{
			exit(EXIT_SUCCESS);
		}
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
		{
			free(cmd);
			continue;
		}
		printf("%s", cmd);
		free(cmd);
	} while (1);
	return (0);
}
