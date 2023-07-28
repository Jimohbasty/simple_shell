#include "shell.h"

/**
 * __buff_free - frees a pointer and NULLs the address
 */
int __buff_free(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}