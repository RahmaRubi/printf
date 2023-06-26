#include "main.h"

/**
 * _printf - printf function
 * @format: format
 * Return: total length
 */

int _printf(const char *format, ...)
{
if (format != NULL)
{
	va_list ptr;
	int i, l = 0, p;

	va_start(ptr, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			p = calling(format[i], ptr);
			if (p != -1)
				l += p;
			else
			{
				print_percent(ptr);
				_putchar(format[i]);
				l += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			l++;
		}
	}
	va_end(ptr);
return (l);




}
return (-1);



}

/**
 * calling - calling function
 * @c: specifier
 * @ptr: argument
 * Return: length
 */

int calling(char c, va_list ptr)
{
	int j, size;
	ff check[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent}
	};
	size = (sizeof(check) / sizeof(check[0]));

	for (j = 0; j < size; j++)
	{
		if (c == check[j].c)
		{
			printf("Return: %i\n", n);
			return (n);
		}
	}
	return (-1);
}
