#include "shell.h"
#include <string.h>

void handle_segfault(int signo __attribute__((unused)));

int ex_code = 0;

/**
 * main - Entry point of the program.
 * @ac: The number of command-line arguments.
 * @av: An array of command-line arguments.
 *
 * Return: 0 on success.
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *__attribute__ ((unused)) cmd1, *cmd_copy = NULL;
	char *argv[MAX_ARGS], *ar[MAX_ARGS];

	int __attribute__ ((unused)) num_arg, r, count = 0;
	signal(SIGSEGV, handle_segfault);
	do {
		count++;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		cmd = read_command();
		if (cmd == NULL)
			exit(ex_code);
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
			continue;
		remwspaces(cmd);
		cmd_copy = strdup(cmd);
		tokenize(cmd_copy, ar);
		tokenize(cmd, argv);
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
		{
			free(cmd);
			free(cmd_copy);
			continue;
		}
		if (_strcmp(argv[0], "exit") == 0)
		{
			r = _1exit(ar[1], count, av[0], argv);
			free(cmd);
			free(cmd_copy);
			if (r == 500)
				continue;
			exit(r);
		}
		if (process_command(argv) == 0)
		{
		}
		else
			_exec(argv, av[0], count);
		free(cmd);
		free(cmd_copy);
	} while (1);
	return (0);
}

/**
 * wspace - check character space or tab
 * @s: character to be checked
 *
 * Return: 1 if successful or 0 if not.
 */

int wspace(char s)
{
	if (s == ' ' || s == '\t')
		return (1);

	return (0);
}

/**
 * remwspaces - remove white spaces
 * @s: string to be checked
 */

void remwspaces(char *s)
{
	int length = _strlen(s);
	int i = 0, j = length - 1, k;
	int l, count, m;

	if (s == NULL)
		return;

	while (i < length && wspace(s[i]))
	{
		i++;
	}
	while (j >= i && wspace(s[j]))
	{
		j--;
	}
	k = 0;
	while (i <= j)
	{
		s[k++] = s[i++];
	}
	s[k] = '\0';
	l = 0;
	count = 0;
	for (m = 0; m <= j; m++)
	{
		if (s[m] != ' ')
		{
			s[l++] = s[m];
			count = 0;
		}
		else if (count == 0)
		{
			s[l++] = s[m];
			count++;
		}
	}
	s[l] = '\0';
}

/**
 * read_command - Read user input from stdin.
 *
 * Return: Pointer to the input command string.
 */
char *read_command(void)
{
	char *cmd1 = _getline();

	signal(SIGINT, handle_sigint);
	return (cmd1);
}
/**
 * handle_sigint - Signal handler for SIGINT (Ctrl+C).
 * @signo: The signal number.
 */
void handle_sigint(int signo __attribute__((unused)))
{
	write(1, "\n", 1);
	if (cmd != NULL)
	{
		free(cmd);
		cmd = NULL;
	}
	exit(0);
}
