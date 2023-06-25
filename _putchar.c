#include "main.h"

/**
 * _putchar - printing char
 * @c: char
 * Return: int
 */

int _putchar(char c)
{
	if (c != '\0')
	{
		write(STDOUT_FILENO, &c, 1);
		return (1);
	}
		return (-1);

}
