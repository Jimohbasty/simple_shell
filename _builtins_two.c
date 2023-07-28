#include "shell.h"

/**
 * __alias - mimics the alias builtin (man alias)
 */
int __alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_list(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

/**
 * set_alias - sets alias to string
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (set_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 */
int print_alias(list_t *alias_node)
{
	char *p = NULL, *a = NULL;

	if (alias_node)
	{
		p = _strchr(alias_node->str, '=');
		for (a = alias_node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * unset_alias - un-sets alias to string
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret_val;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret_val = delete_node_at_index(&(info->alias),
					  get_node_at_index(info->alias,
							    node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret_val);
}

/**
 * __history - displays the history list
 */
int __history(info_t *info)
{
	print_list(info->history);
	return (0);
}
