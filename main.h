#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdarg.h>

/**
 * struct PrintType - Associates a format specifier with a print function
 * @type: The format specifier (e.g., "c", "s", "%", etc.)
 * @print_type_function: Pointer to the function that handles the specifier
 *
 * Description: This structure is used to map each format specifier to its
 * corresponding function for handling variadic arguments in `_printf`.
 */
typedef struct PrintType
{
	char *type;
	int (*print_type_function)(va_list args);
} PrintType_t;

int _printf(const char *format, ...);
int _putchar(char character);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_number(unsigned int num);

#endif /* __MAIN_H__ */
