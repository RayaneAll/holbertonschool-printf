#include "main.h"
#include "print_percent.c"
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
* print_integer - Prints an integer
* @args: va_list containing the integer
* Return: Number of characters printed
*/
int print_integer(va_list args)
{
	int n = va_arg(args, int);

	unsigned int num;

	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	count += print_number(num);

	return (count);
}

/**
* print_number - Prints an unsigned integer recursively
* @num: The unsigned integer to print
* Return: Number of characters printed
*/
int print_number(unsigned int num)
{
	int count = 0;

	if (num / 10)
		count += print_number(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

/**
* _printf - Prints formatted output
* @format: Format string
* Return: Number of characters printed
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
