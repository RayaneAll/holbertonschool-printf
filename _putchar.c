#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: 1 on success, -1 on failure
 *
 * Description: This function sends a single character to the standard
 * output (stdout) using the `write` system call.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
