#include "main.h"
/**
 * print_char - char printing
 * @ptr: char argument
 * Return: length
 */

int print_char(va_list ptr)
{
	return (_putchar(va_arg(ptr, int)));
}

/**
 * print_string - string printing
 * @ptr: string argument
 * Return: length
 */

int print_string(va_list ptr)
{
	char *string;

	string = va_arg(ptr, char *);
	if (!string)
		string = "(null)";
	return (write(1, string, _strlen(string)));
}

/**
 * print_percent - percent  printing
 * @ptr: ignored argument
 * Return: length
 */

int print_percent(__attribute__((unused)) va_list ptr)
{
	return (_putchar('%'));
}

/**
 * _strlen - counnting string length
 * @c: string argument
 * Return: counter
 */

int _strlen(char *c)
{
	int count = 0;

	while (c[count])
		count++;
	return (count);
}

/**
 * print_int - print an integer
 * @args: argument
 * Return: no. of printed chars
 */
int print_int(va_list args)
{
	int rev = 0, cnt = 0, cnt_num = 0, n = va_arg(args, int);

	if (!n)
		return (_putchar('0'));
	if (n == -2147483648)
	{
		n = 147483648;
		_putchar('-');
		_putchar('2');
		cnt = 2;
	}
	if (n < 0)
	{
		n *= -1;
		_putchar('-');
		cnt++;
	}
	if (n >= 1000000000)
	{
		_putchar('0' + n / 1000000000);
		n -= (n / 1000000000) * 1000000000;
		cnt++;
	}

	while (n)
	{
		rev *= 10;
		rev += n % 10;
		n /= 10;
		cnt_num++;
	}
	while (cnt_num--)
	{
		_putchar(rev % 10 + '0');
		rev /= 10;
		cnt++;
	}
	return (cnt);
}
