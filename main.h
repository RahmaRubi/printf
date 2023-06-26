#ifndef main_H
#define main_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * list - struct
 * @c: specifier member
 * @p: related function
 */
struct list
{
	char c;
	int (*p)(va_list ptr);
};

/**
 * typedef struct list ff - struct define
 * @list: ff
 * @ff: eshta
 */

typedef struct list ff;
int print_char(va_list ptr);
int print_string(va_list ptr);
int print_percent(va_list ptr);
int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *c);
int calling(char c, va_list ptr);

#endif
