#include "shell.h"



/**
 * set_info - initializes info_t struct
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->file_name = av[0];
	if (info->arg)
	{
		info->argv = __strtok_one(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees info_t struct fields
 */
void free_info(info_t *info, int free_all)
{
	__f_free(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (free_all)
	{
		if (!info->cmd_buffer)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		__f_free(info->environ);
		info->environ = NULL;
		__buff_free((void **)info->cmd_buffer);
		if (info->read_file_dir > 2)
			close(info->read_file_dir);
		_putchar(BUFFER_FLUSH);
	}
}

/**
 * clear_info - initializes info_t struct
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}