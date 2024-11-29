#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdarg.h>

/**
 * struct PrintType - Structure to map format specifiers to functions
 * @type: The format specifier
 * @print_type_function: Pointer to the corresponding function
 *
 * Description: This structure pairs each format specifier with its handler
 * function to process variadic arguments for `_printf`.
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
int print_integer(va_list arguments);
int print_number(unsigned int num);

#endif /* __MAIN_H__ */
