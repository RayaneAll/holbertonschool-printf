#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Prints a single character
 * @args: va_list containing the character
 *
 * Return: The number of characters printed (always 1)
 *
 * Description: Retrieves a character from the variadic argument list
 * and prints it using `_putchar`.
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Prints a string
 * @args: va_list containing the string
 *
 * Return: The number of characters printed
 *
 * Description: Prints each character in the string retrieved from
 * the variadic argument list. If the string is NULL, "(null)" is printed.
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
 *
 * Return: The number of characters printed (always 1)
 *
 * Description: Prints a single '%' character. The `args` parameter is
 * unused since no arguments are required for this operation.
 */
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}

/**
 * print_integer - Prints an integer
 * @args: va_list containing the integer
 *
 * Return: The number of characters printed
 *
 * Description: Retrieves an integer from the variadic argument list
 * and prints it using `_putchar`. Negative numbers are handled correctly.
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
 *
 * Return: The number of characters printed
 *
 * Description: Recursively breaks down the integer into its digits,
 * printing each digit using `_putchar`.
 */
int print_number(unsigned int num)
{
	int count = 0;

	if (num / 10)
		count += print_number(num / 10);

	count += _putchar((num % 10) + '0');
	return (count);
}
