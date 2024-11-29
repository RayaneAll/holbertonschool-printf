#include "main.h"
#include <stdarg.h>

/**
 * _printf - Produces output according to a format
 * @format: Character string containing zero or more directives
 *
 * Description: Mimics the standard `printf` function. Processes the format
 * string to handle specifiers for characters (%c), strings (%s), integers
 * (%d, %i), and percent signs (%%). If `%` is followed by `\0`, it does not
 * print anything.
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

	if (!format) /* Handle NULL format string */
		return (-1);

	va_start(args, format);

	while (*format) /* Loop through each character in the format string */
	{
		if (*format == '%') /* Handle format specifier */
		{
			format++;
			if (*format == '\0') /* If '%' is followed by NULL, stop processing */
				break;

			/* Check for valid specifier */
			for (j = 0; print_types[j].type; j++)
			{
				if (*format == *(print_types[j].type))
				{
					count += print_types[j].print_type_function(args);
					break;
				}
			}

			if (!print_types[j].type) /* If no valid specifier, print '%' and the character */
				count += _putchar('%') + _putchar(*format);
		}
		else /* Print regular characters */
		{
			count += _putchar(*format);
		}
		format++; /* Move to the next character */
	}

	va_end(args); /* Clean up variadic arguments */
	return (count);
}
