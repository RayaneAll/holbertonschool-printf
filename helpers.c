#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Prints a single character
 * @args: List of variadic arguments containing the character
 *
 * Description: Extracts a character from the variadic argument list and
 * prints it using `_putchar`.
 *
 * Return: 1 on success
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Prints a string
 * @args: List of variadic arguments containing the string
 *
 * Description: Extracts a string from the variadic argument list and prints
 * each character in the string using `_putchar`. If the string is NULL, it
 * prints "(null)".
 *
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
 * @args: List of variadic arguments (unused)
 *
 * Description: Prints a '%' character. The `args` parameter is ignored since
 * no argument is needed for this specifier.
 *
 * Return: 1 on success
 */
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}

/**
 * print_integer - Prints an integer
 * @args: List of variadic arguments containing the integer
 *
 * Description: Extracts an integer from the variadic argument list and prints
 * it using `_putchar`. Handles both positive and negative integers.
 *
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
 * print_number - Prints an unsigned integer
 * @num: The unsigned integer to print
 *
 * Description: Recursively breaks down the integer into its digits and prints
 * each digit using `_putchar`.
 *
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
