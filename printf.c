#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_char(char c);
int print_string(char *s);
int print_number(int n);

/**
 * _printf - Produces output according to a format
 * @format: Character string containing zero or more directives
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *s;
	int n;

	va_start(args, format);
	while (format && *format)
	{
		if (*format != '%')
			count += write(1, format, 1);
		else
		{
			format++;
			if (*format == 'c')
				count += print_char(va_arg(args, int));
			else if (*format == 's')
				count += print_string(va_arg(args, char *));
			else if (*format == '%')
				count += write(1, "%", 1);
			else if (*format == 'd' || *format == 'i')
			{
				n = va_arg(args, int);
				count += print_number(n);
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
