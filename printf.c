#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format
 * @format: Character string containing zero or more directives
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{

	va_list args;
	int count = 0;
	char c, *s;

	va_start(args, format);
	while (format && *format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				s = s ? s : "(null)";
				while (*s)
					count += write(1, s++, 1);
			}
			else if (*format == '%')
				count += write(1, "%", 1);
			else if (*format == 'd' || *format == 'i')
				count += print_number(va_arg(args, int));
			else
				count += write(1, "%", 1) + write(1, format, 1);
		}
		format++;
	}
	
	va_end(args);
	
	return (count);
}
