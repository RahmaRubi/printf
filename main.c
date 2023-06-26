#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2,len3,len4;

    len = _printf(NULL);
    len2 = printf(NULL);
    len3 = _printf("String:[%s]\n", NULL);
    len4 = printf("String:[%s]\n", NULL);
    printf("return values: %d %d %d %d\n", len, len2, len3, len4);
    return (0);
}
