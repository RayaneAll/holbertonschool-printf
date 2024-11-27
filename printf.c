#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* print_char - Prints a character
* @args: va_list containing the character
* Return: Number of characters printed
*/
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
* print_string - Prints a string
* @args: va_list containing the string
* Return: Number of characters printed
*/
int print_string(va_list args)
{
	char *string = va_arg(args, char *);

	int count = 0;

	if (!string)
		string = "(null)";
	while (*string)
		count += _putchar(*string++);
	return (count);
}

/**
* print_percent - Prints a percent symbol
* @args: va_list (unused)
* Return: Number of characters printed
*/
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}

/**
* _printf - prints formatted output
* @format: format string
*
* Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	PrintType_t print_types[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};
	va_list args;
	int i, j, count = 0;

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
