#include <unistd.h>

/**
* _putchar - Writes a character to stdout
* @c: The character to print
*
* Description: Sends a single character to the standard output (stdout)
* using the `write` system call.
*
* Return: 1 on success, -1 on failure
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
