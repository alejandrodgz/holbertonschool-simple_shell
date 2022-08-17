#include "shell.h"

/**
 * _puts - writes to the STDOUT
 * @s: pointer to the string to be rpinted
 */
void _puts(char *s)
{
	write(STDOUT_FILENO, s, _str_lenght(s));
}

/**
 * _putse - writes to the STDERR
 * @s: pointer to the string to be rpinted
 */
void _putse(char *s)
{
	write(STDERR_FILENO, s, _str_lenght(s));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(const char c)
{
	return (write(1, &c, 1));
}
