#include "main.h"

/**
 * _printf - printf function
 * @format: format
 * Return: total length
 */

int _printf(const char *format, ...)
{
	va_list ptr;
	int i, cnt = 0;

	va_start(ptr, format);
	if (format == NULL)
		return (-1);

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

/**
 * calling - calling function
 * @c: specifier
 * @ptr: argument
 * Return: length
 */
int calling(char c, va_list ptr)
{
	int i, size;
	ls check[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'i', print_int},
		{'d', print_int},
		{'b', print_binary},
		{'R', rot_trans},
		{'r', rev_string}
	};
	size = (sizeof(check) / sizeof(check[0]));

	for (i = 0; i < size; i++)
	{
		if (c == check[i].c)
			return (check[i].p(ptr));
	}
	return (print_unknown(c));
}
