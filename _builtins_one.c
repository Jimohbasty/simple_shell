#include "shell.h"

/**
 * __cd - changes the current directory of the process
 */
int __cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_return;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts(">>Cannot get current working dir<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_return =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_return = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_return =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_return = chdir(info->argv[1]);
	if (chdir_return == -1)
	{
		__p_error(info, "can't cd to ");
		__error_puts(info->argv[1]), __error_putchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * __exit - exits the shell
 */
int __exit(info_t *info)
{
	int exit_check;

	if (info->argv[1])
	{
		exit_check = _erratoi(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			__p_error(info, "Illegal number: ");
			__error_puts(info->argv[1]);
			__error_putchar('\n');
			return (1);
		}
		info->error_number = _erratoi(info->argv[1]);
		return (-2);
	}
	info->error_number = -1;
	return (-2);
}

/**
 * __help - changes the current directory of the process
 */
int __help(info_t *info)
{
	char **args_array;

	args_array = info->argv;
	_puts("Check the official GNU or C documentation sites\n");
	if (0)
		_puts(*args_array);
	return (0);
}