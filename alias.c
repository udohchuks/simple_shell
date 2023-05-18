#include "shell.h"

int alias_command(char *argv[MAX_ARGS], int num_arg __attribute__((unused)))
{
	int i = 0;
	static int num_aliases = 4;
	alias_t aliases[100] =
	{
		{"l", "ls -CF"},
		{"la", "ls -A"},
		{"ll", "ls -alF"},
		{"ls", "ls --color=auto"},
		{NULL, NULL}
	};
	if (_strcmp(argv[0], "alias") != 0)
	{
		return (1);
	}
	if (_strcmp(argv[0], "alias") == 0 && num_arg == 1)
	{
		while (aliases[i].name != NULL)
		{
			write(1, "alias " ,7);
			write(1,aliases[i].name,_strlen(aliases[i].name));
			write(1, "='", 2);
			write(1, aliases[i].alias_cmd, _strlen(aliases[i].alias_cmd));
			write(1,"'", 1);
			write(1, "\n", 1);
			i++;
		}
	}
	if (argv[1] != NULL)
	{
		if (has_equal(argv[1]) && _strcmp(argv[0], "alias") == 0)
		{

		}
		else if (has_equal(argv[1]) == 0 && _strcmp(argv[0], "alias") == 0)
		{
			int i;

			for (i = 0; i < num_aliases; i++)
			{
				if (strcmp(argv[1], aliases[i].name) == 0)
				{
					write(1, "alias " ,7);
					write(1,aliases[i].name,_strlen(aliases[i].name));
					write(1, "='", 2);
					write(1, aliases[i].alias_cmd, _strlen(aliases[i].alias_cmd));
					write(1,"'", 1);
					write(1, "\n", 1);
					return (0);
				}
			}
		}
		else
		{
			return (0);
		}
	}
		return (1);
}