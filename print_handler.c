#include "main.h"
/**
 * _print_handler - Prints an argument based on its type
 */
int _print_handler(const char *fmt, int *ind, va_list list,
		   char buffer[], int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', _char_prints}, {'s', _print_strs}, {'%', _print_percent},
		{'i', _print_int}, {'d', _print_int}, {'b', _print_binary},
		{'u', _print_unsigned}, {'o', _print_octal},
		{'x', __print_hexadecimal}, {'X', _print_upper_hex},
		{'p', _print_ptr}, {'S', _print_un_printable},
		{'r', _reverse_print}, {'R', print_rot13string}, {'\0', NULL}};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}