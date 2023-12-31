#include "main.h"

/**
 * print_octal - print the octal of a number
 *
 * @ptr: argument
 *
 * Return: no. of printed chars
 */
int print_octal(va_list ptr)
{
	char octal[100];
	unsigned int num, i = 0, j;

	num = va_arg(ptr, unsigned int);
	while (num)
	{
		octal[i] = num % 8 + '0';
		num /= 8;
		i++;
	}
	j = i;
	while (j--)
		_putchar(octal[j]);
	if (!i)
		return (_putchar('0'));
	return (i);
}

/**
 * print_hexa - hexadecimal of a number
 *
 * @ptr: argument
 *
 * Return: no. of printed chars
 */
int print_hexa(va_list ptr)
{
	unsigned int num, magic, i;
	int start = -1;

	num = va_arg(ptr, unsigned int);
	magic = 0xf0000000;
	for (i = 7; magic; i--)
	{
		if (start == -1 && (magic & num))
			start = i;
		if (start != -1)
		{
			if ((magic & num) >> i * 4 >= 10)
				_putchar('a' + ((magic & num) >> i * 4) - 10);
			else
				_putchar('0' + ((magic & num) >> i * 4));
		}
		magic >>= 4;
	}
	if (start == -1)
	{
		_putchar('0');
		return (1);
	}
	return (start + 1);
}

/**
 * print_non_printable - print the ASCII code value in hexadecimal
 *
 * @ptr: argument
 *
 * Return: no. of printed chars
 */
int print_non_printable(va_list ptr)
{
	char *str;
	int i, done = 0;
	char hexa[] = "0123456789ABCDEF";
	str = va_arg(ptr, char *);
	if (!str)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || (str[i] >= 127))
		{
			done++;
			_putchar('\\');
			_putchar('x');
			if (str[i] &  0xf0)
				_putchar((hexa[(str[i] & 0xf0) >> 4]));
			else
				_putchar('0');
			_putchar((hexa[str[i] & 0x0f]));
		}
		else
			_putchar(str[i]);
	}
	return (i + done * 3);
}
