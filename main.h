#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdarg.h>

/**
* struct PrintType - A structure to print a specific type
* @type: The type
* @print_type_function: Function pointer to print the type
*
* Cette structure associe un spécificateur de format à une fonction.
*/

typedef struct PrintType
{
	char *type;

	int (*print_type_function)(va_list args);
} PrintType_t;

int _printf(const char *format, ...);

int _putchar(char character);

int print_char(va_list arguments);
int print_string(va_list arguments);
int print_percent(va_list arguments);

#endif
