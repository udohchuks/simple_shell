#include "shell.h"

/**
 * my_strtok - strtok implementation
 * @str: string
 * @delim: delimiter
 * Return: token
 */

char *my_strtok(char *str, char const *delim)
{
	static char *ptr;
	int size = 0;
	char *token;
	int i = 0, j;

	if (str != NULL)
	{
		ptr = str;
	}
	while (ptr[i] != '\0')
	{
		if (ptr[i] == *delim)
		{
			ptr[i] = '\0';
			token = ptr;
			ptr = &ptr[i + 1];
			return (token);
		}
		i++;
	}
	if (ptr[0] != '\0')
	{
		while (ptr[size] != 0)
			size++;
		token = ptr;
		ptr += size; /* update ptr to '\0' */
		return (token);
	}
	return (NULL);
}
