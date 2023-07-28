#include "shell.h"

/**
 * get_node_at_index - gets the index of a node
 */
ssize_t get_node_at_index(list_t *head_ptr, list_t *node_ptr)
{
	size_t i = 0;

	while (head_ptr)
	{
		if (head_ptr == node_ptr)
			return (i);
		head_ptr = head_ptr->next;
		i++;
	}
	return (-1);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 */
char **list_to_strings(list_t *head_node)
{
	list_t *node = head_node;
	size_t i = list_len(head_node), j;
	char **strs;
	char *str;

	if (!head_node || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * list_len - determines length of linked list
 */
size_t list_len(const list_t *head_ptr)
{
	size_t i = 0;

	while (head_ptr)
	{
		head_ptr = head_ptr->next;
		i++;
	}
	return (i);
}

/**
 * print_list - prints all elements of a list_t linked list
 */
size_t print_list(const list_t *head_ptr)
{
	size_t i = 0;

	while (head_ptr)
	{
		_puts(convert_number(head_ptr->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head_ptr->str ? head_ptr->str : "(nil)");
		_puts("\n");
		head_ptr = head_ptr->next;
		i++;
	}
	return (i);
}