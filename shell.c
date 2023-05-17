#include "shell.h"
/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	char *cmd;
	char *full_path;

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
			continue;
		}
		/* Testing*/
		full_path = which(cmd);
		dprintf(1, "%s\n", full_path);
		free(full_path);
		/* End of test*/

		free(cmd);
	} while (1);
	return (0);
}
