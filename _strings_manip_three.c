#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= WRITE_BUFFER_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _strcpy - copies a string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _puts - prints an input string
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _strdup - duplicates a string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret_str;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret_str = malloc(sizeof(char) * (length + 1));
	if (!ret_str)
		return (NULL);
	for (length++; length--;)
		ret_str[length] = *--str;
	return (ret_str);
}