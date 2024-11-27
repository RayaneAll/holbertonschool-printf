#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
