#include "main.h"
#include <stdarg.h>

/**
 * _printf - Prints formatted output
 * @format: The format string containing characters and format specifiers
 *
 * Return: The total number of characters printed
 *
 * Description: Mimics the functionality of the standard `printf` function.
 * It supports the following format specifiers:
 * - %c: Prints a single character
 * - %s: Prints a string
 * - %d: Prints a decimal integer
 * - %i: Prints an integer
 * - %%: Prints a percent symbol
 */
int _printf(const char *format, ...)
{
	PrintType_t print_types[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};
	va_list args;
	int j, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (j = 0; print_types[j].type; j++)
			{
				if (*format == *(print_types[j].type))
				{
					count += print_types[j].print_type_function(args);
					break;
				}
			}
			if (!print_types[j].type)
				count += _putchar('%') + _putchar(*format);
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}

	va_end(args);

	return (count);
}
