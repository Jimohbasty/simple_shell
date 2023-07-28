#include "shell.h"

/**
 * _realloc - reallocates a block of memory
 */
void *_realloc(void *ptr, unsigned int prev_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == prev_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	prev_size = prev_size < new_size ? prev_size : new_size;
	while (prev_size--)
		p[prev_size] = ((char *)ptr)[prev_size];
	free(ptr);
	return (p);
}

/**
 * _memset - fills memory with a constant byte
 */
char *_memset(char *str, char byte, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		str[i] = byte;
	return (str);
}

/**
 * __f_free - frees a string of strings
 */
void __f_free(char **str_of_strs)
{
	char **a = str_of_strs;

	if (!str_of_strs)
		return;
	while (*str_of_strs)
		free(*str_of_strs++);
	free(a);
}