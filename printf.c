#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args);
int print_percent(va_list args);

/**
 * _printf - Produces output according to a format
 * @format: Character string containing zero or more directives
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int (*print_func)(va_list);
	char *ptr = (char *)format;

	va_start(args, format);
	while (ptr && *ptr)
	{
		if (*ptr != '%')
		{
			count += write(1, ptr, 1);
		}
		else
		{
			ptr++;
			print_func = get_print_func(*ptr);
			if (print_func)
				count += print_func(args);
			else
				count += write(1, ptr - 1, 2);
		}
		ptr++;
	}
	va_end(args);
	return (count);
}

/**
 * get_print_func - Selects the correct function for printing
 * @s: The format specifier
 * Return: A pointer to the printing function
 */
int (*get_print_func(char s))(va_list)
{
	print_t funcs[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_number},
		{'i', print_number},
		{'%', print_percent},
		{0, NULL}
	};
	int i = 0;

	while (funcs[i].spec)
	{
		if (funcs[i].spec == s)
			return (funcs[i].f);
		i++;
	}
	return (NULL);
}

