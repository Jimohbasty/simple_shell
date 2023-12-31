#include "main.h"
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 */

int _printf(const char *format, ...)
{
	int i, print = 0, print_chars = 0;
	int flags, width, prec, size, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			print_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = _get_flags(format, &i);
			width = _get_width(format, &i, args);
			prec = _get_precision(format, &i, args);
			size = _get_size(format, &i);
			++i;
			print = _print_handler(format, &i, args, buffer, flags, width, prec, size);
			if (print == -1)
				return (-1);
			print_chars += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(args);

	return (print_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}