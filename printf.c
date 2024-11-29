#include "main.h"
#include <stdarg.h>

/**
 * _printf - Prints formatted output
 * @format: The format string containing characters and specifiers
 *
 * Description: Mimics the standard `printf` function. Processes the format
 * string to handle specifiers for characters (%c), strings (%s), integers
 * (%d, %i), and percent signs (%%).
 *
 * Return: Total number of characters printed
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
