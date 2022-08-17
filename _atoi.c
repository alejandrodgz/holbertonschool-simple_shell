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
