#include "main.h"
int _printf(const char *format, ...)
{
if (format != NULL)
{
	va_list ptr;
	int i, l;

	va_start (ptr, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			calling(format[i]);
				
		}
		else
		{
			_putchar(format[i]);
			l++;
		}
	
	}
return (l);




}
return (-1);



}
int calling (char c, va_list ptr)
{	
	int j, size;
	struct list check[]
	{
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent}
	};
	size = (sizeof(check) / sizeof(check[0]));

	for (j = 0; j < size; j++)
	{
		if (c == check[j].c)
			check[j].p(ptr);
	
	}
