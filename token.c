#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * token1 - prints every word of a string
 * @string: text
 * @sep: sep
 */

void token1(char *string, char *sep)
{
	char *token;
	size_t b = 0;

	token = strtok(string, sep);
	while (token != NULL)
	{
		b = strlen(token);
		write(STDOUT_FILENO, token, b);
		write(STDOUT_FILENO, "\n", 2);
		token = strtok(NULL, sep);
	}
	return;
}
