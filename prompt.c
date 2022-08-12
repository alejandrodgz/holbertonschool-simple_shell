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
	size_t n = 0;
	ssize_t h;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 1);
		h = getline(&line, &n, stdin);
		write(STDOUT_FILENO, line, h);
		write(STDOUT_FILENO, "\n", 2);
	}
	return (0);
}
