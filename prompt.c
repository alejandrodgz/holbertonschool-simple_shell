#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 *
 *
 *
 */

int main (void)
{
	char *prompt = "$";
	char *line;
	char *token;
	char *sep = " ";
	size_t n = 0;
	ssize_t h, b;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 1);
		h = getline(&line, &n, stdin);
		token = strtok(line, sep);
		while (token != NULL)
		{
			b = strlen(token);
			write(STDOUT_FILENO, token, b);
			write(STDOUT_FILENO, "\n", 2);
			token = strtok(NULL, sep);
		}
	}
	return (0);
}
