#include "shell.h"
#include <limits.h>

/**
 * _atoi - looks for numbers of a string and
 * converts in integer
 * @s: pointer to the string to be iterated
 * Return: the number f a sign of an array or
 * 0 if no a number
 */

int _atoi(char *s)
{
	int arr;
	int sig = 0;
	int num = 0;
 	int outp = 0;

	for (arr = 0; s[arr] != '\0'; arr++)
	{
		if (s[arr] == '-')
		{
			sig++;
		}
		if (s[arr] >= 48 && s[arr] <= 57)
		{
			num = num * 10 - (s[arr] - '0');
			outp = 1;
		}
		else if (outp == 1)
		{
			break;
		}
	}
	if ((sig - 1) % 2 != 0)
	{
		num = num * -1;
	}
	return (num);
}


/**
 * _printd - print any number
 * @num: number
 *
 * Return: Nothing
 */

void _printd(int num)
{
	unsigned int num_1;

	if (num < 0)
	{
		_putchar('-');
		num_1 = -num;
	}
	else
		num_1 = num;
	if (num_1 / 10)
	{
		_printd(num_1 / 10);
	}
	_putchar(num_1 % 10 + '0');
}

/**
 * _putchar1 - writes the character c to stderror
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar1(const char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * _printd1 - print any number to the stderr
 * @num: number
 *
 * Return: Nothing
 */

void _printd1(int num)
{
	unsigned int num_1;

	if (num < 0)
	{
		_putchar('-');
		num_1 = -num;
	}
	else
		num_1 = num;
	if (num_1 / 10)
	{
		_printd(num_1 / 10);
	}
	_putchar1(num_1 % 10 + '0');
}
