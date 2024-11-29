#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/* Prototypes for printing functions */
int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args);
int print_percent(va_list args);

/**
 * _printf - Produces output according to a format
 * @format: Character string containing zero or more directives
 *
 * Description: Mimics the functionality of the standard printf function.
 * and the percent symbol (%%).
 *
 * Return: The total number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;                /* List to store variadic arguments */
	int count = 0;               /* Counter for the total printed characters */
	int (*print_func)(va_list);  /* Pointer to the corresponding print function */
	char *ptr = (char *)format;  /* Pointer to traverse the format string */

	/* Start variadic argument processing */
	va_start(args, format);

	/* Loop through the format string */
	while (ptr && *ptr)
	{
		if (*ptr != '%')  /* If not a specifier, write the character as is */
		{
			count += write(1, ptr, 1);
		}
		else  /* If it's a format specifier */
		{
			ptr++;  /* Move to the specifier character */
			print_func = get_print_func(*ptr);
			if (print_func)  /* If a valid function is found, call it */
				count += print_func(args);
			else  /* If no valid function, print '%' and the specifier */
				count += write(1, ptr - 1, 2);
		}
		ptr++;  /* Move to the next character in the format string */
	}

	/* Clean up variadic arguments */
	va_end(args);
	return (count);  /* Return the total number of characters printed */
}

/**
 * get_print_func - Selects the correct function for printing
 * @s: The format specifier character
 *
 * Description: Matches the format specifier with its corresponding function
 * from an array of structures.
 *
 * Return: A pointer to the appropriate printing function, or NULL if no match.
 */
int (*get_print_func(char s))(va_list)
{
	print_t funcs[] = {  /* Array mapping specifiers to their functions */
		{'c', print_char},
		{'s', print_string},
		{'d', print_number},
		{'i', print_number},
		{'%', print_percent},
		{0, NULL}  /* Sentinel value to mark the end of the array */
	};
	int i = 0;

	/* Loop through the array to find a matching specifier */
	while (funcs[i].spec)
	{
		if (funcs[i].spec == s)
			return (funcs[i].f);  /* Return the matching function */
		i++;
	}

	return (NULL);  /* Return NULL if no match is found */
}
