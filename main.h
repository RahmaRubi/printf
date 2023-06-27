#ifndef main_H
#define main_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct list - struct for format specifier and related function
 * @c: format specifier member
 * @p: related function
 */
typedef struct list
{
	char c;
	int (*p)(va_list ptr);
} ls;

int print_char(va_list ptr);
int print_string(va_list ptr);
int print_percent(va_list ptr);
int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *c);
int calling(char c, va_list ptr);
int print_int(va_list ptr);
int print_unknown(char c);
int print_binary(va_list ptr);
int rot_trans(va_list ptr);
int rev_string(va_list ptr);
int print_unsigned(va_list ptr);
#endif
