#include "shell.h"

/**
 * free_list - frees all nodes of a list
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

/**
 * add_node_end - adds a node to the end of the list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * delete_node_at_index - deletes node at given index
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * add_node - adds a node to the start
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head_node;

	if (!head)
		return (NULL);
	new_head_node = malloc(sizeof(list_t));
	if (!new_head_node)
		return (NULL);
	_memset((void *)new_head_node, 0, sizeof(list_t));
	new_head_node->num = num;
	if (str)
	{
		new_head_node->str = _strdup(str);
		if (!new_head_node->str)
		{
			free(new_head_node);
			return (NULL);
		}
	}
	new_head_node->next = *head;
	*head = new_head_node;
	return (new_head_node);
}

/**
 * print_list_str - prints only the string element
 */
size_t print_list_str(const list_t *head_ptr)
{
	size_t i = 0;

	while (head_ptr)
	{
		_puts(head_ptr->str ? head_ptr->str : "(nil)");
		_puts("\n");
		head_ptr = head_ptr->next;
		i++;
	}
	return (i);
}