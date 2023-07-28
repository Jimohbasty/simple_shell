#include "main.h"

/**
 * _print_hexa - Prints a hexadecimal number in lower or upper
 */
int _print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (_write_unsigned(0, i, buffer, flags, width, precision, size));
}

/**
 * _print_unsigned - Prints an unsigned number
 */
int _print_unsigned(va_list types, char buffer[],
		    int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = _convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (_write_unsigned(0, i, buffer, flags, width, precision, size));
}

/**
 * __print_hexadecimal - Prints an unsigned number in hexadecimal notation
 */
int __print_hexadecimal(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
	return (_print_hexa(types, "0123456789abcdef", buffer,
			    flags, 'x', width, precision, size));
}

/**
 * _print_upper_hex - Prints an unsigned number in upper hexadecimal notation
 */
int _print_upper_hex(va_list types, char buffer[],
		     int flags, int width, int precision, int size)
{
	return (_print_hexa(types, "0123456789ABCDEF", buffer,
			    flags, 'X', width, precision, size));
}

/**
 * _print_octal - Prints an unsigned number in octal notation
 */
int _print_octal(va_list types, char buffer[],
		 int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (_write_unsigned(0, i, buffer, flags, width, precision, size));
}