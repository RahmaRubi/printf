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
	write(STDOUT_FILENO, string, _strlen(string));
	return (_strlen(string));
}

/**
 * print_percent - percent  printing
 * @ptr: ignored argument
 * Return: length
 */

int print_percent(va_list ptr)
{
	(void) ptr;
	return (_putchar('%'));
}

/**
 * _strlen - counnting string length
 * @c: string argument
 * Return: counter
 */

int _strlen(char *c)
{
	int count;

	count = 0;
	while (c[count])
	count++;
	return (count - 1);
}