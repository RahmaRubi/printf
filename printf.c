#include "main.h"

/**
 * _printf - printf function
 * @format: format
 * Return: total length
 */

int _printf(const char *format, ...)
{
	if (format)
	{
		va_list ptr;
		int i, cnt = 0;

		va_start(ptr, format);
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] == '%')
			{
				i++;
				if (format[i] == '\0')
					return (-1);
				cnt += calling(format[i], ptr);
			}
			else
			{
				_putchar(format[i]);
				cnt++;
			}
		}
		va_end(ptr);
		return (cnt);
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
	ls check[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'i', print_int},
		{'d', print_int}
	};
	size = (sizeof(check) / sizeof(check[0]));

	for (j = 0; j < size; j++)
	{
		if (c == check[j].c)
			return (check[j].p(ptr));
	}
	return (print_unkown(c));
}
