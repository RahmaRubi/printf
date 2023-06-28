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
/**
 * rev_string - print a string in reverse
 *
 * @ptr: argument
 *
 * Return: no. of printed chars
 */
int rev_string(va_list ptr)
{
	char *string;
	int len, i;

	len = 0, i = 0;

	string = va_arg(ptr, char *);
	if (!string)
		string = "(null)";
	len = _strlen(string);
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(string[i]);
	}
	return (len);
}

/**
 * print_unsigned - print unsigned integer
 *
 * @ptr: argument
 *
 * Return: no. of printed chars
 */
int print_unsigned(va_list ptr)
{
	unsigned int num, cpy, i, cnt = 0;
	char str[] = "0000000000";

	num = va_arg(ptr, unsigned int);
	cpy = num;
	while (cpy)
	{
		cnt++;
		cpy /= 10;
	}
	for (i = 0; num; i++)
	{
		str[cnt - i - 1] = '0' + num % 10;
		num /= 10;
	}
	return (write(1, str, cnt));
}
