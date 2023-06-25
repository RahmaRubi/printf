#ifndef main_H
#define main_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

struct list
{
	char c;
	int (*p)(va_list ptr);
};
int print_char(va_list ptr);
int print_string(va_list ptr);
int print_percent(va_list ptr);
int _printf(const char *format, ...);
int _putchar(char c);
int _strlen (char *c);


#endif
