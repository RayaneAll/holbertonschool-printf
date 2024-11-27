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
