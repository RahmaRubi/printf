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
 * @ptr: arguement
 *
 * Return: no. of printed chars
 */
int print_binary(va_list ptr)
{
	int start = -1, i;
	unsigned int n;

	n = va_arg(ptr, unsigned int);

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


/**
 * rot_trans - rotate every char by 13
 *
 * @ptr: argument
 *
 * Return: no. of printed chars
 */
int rot_trans(va_list ptr)
{
	char *str;
	int i;

	str = va_arg(ptr, char *);
	if (!str)
		str = "(null)";
	for (i = 0; i < _strlen(str); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			_putchar((str[i] - 'a' + 13) % 26 + 'a');
		else if (str[i] >= 'A' && str[i] <= 'Z')
			_putchar((str[i] - 'A' + 13) % 26 + 'A');
		else
			_putchar(str[i]);
	}
	return (i);
}
