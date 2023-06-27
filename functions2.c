#include "main.h"

/**
 * print_unknown - print unknown specifiers
 *
 * @c: the char to print
 *
 * Return: 1 (Always)
 */
int print_unknown(char c)
{
	_putchar('%');
	_putchar(c);
	return (2);
}

/**
 * print_binary - print the binary repersentation of the number
 *
 * @args: arguement
 *
 * Return: no. of printed chars
 */
int print_binary(va_list args)
{
	int start = -1, i;
	unsigned int n;

	n = va_arg(args, unsigned int);

	for (i = 31; i >= 0; i--)
	{
		if (start == -1 && (n >> i & 1) == 1)
			start = i;
		if (start != -1)
			_putchar('0' + (n >> i & 1));
	}
	if (start == -1)
	{
		_putchar('0');
		return (1);
	}
	return (start + 1);
}
