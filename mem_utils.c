#include "shell.h"
/**
 * _memcpy - copies memory from the source to destination
 * @dest: destination
 * @src: source
 * @n: size of memory to be copied
 * Return: memory of destination
 */
void *_memcpy(void *dest, void *src, size_t n)
{
	char *cdest = (char *)(dest);
	const char *csrc = (const char *)(src);
	size_t i = 0;

	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
/**
 * _realloc - realloc function
 * @ptr: old malloc pointer
 * @size: new size
 * Return: new ptr
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
