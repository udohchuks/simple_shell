#include "shell.h"
/**
 * _strcmp - compare 2 strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0 if equaul and otherwise if not equal
 */
int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (str1[i] - str2[i]);
}
/**
 * _strlen - string length
 * @str: string
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strncpy - string copy of n limit
 * @dest: destination
 * @src: source string
 * @size: number of char to be copied
 * Return: sized of char copied
 */
int _strncpy(char *dest, char *src, int size)
{
	int i = 0;

	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
