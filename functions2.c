#include "main.h"

/**
 * print_unknown - print unknown specifiers
 * @c: the char to print
 * Return: 1 (Always)
 */
int print_unkown(char c)
{
	print_percent(NULL);
	_putchar(c);
	return (2);
}
