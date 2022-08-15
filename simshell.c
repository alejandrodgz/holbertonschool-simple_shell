#include "main.h"

/**
 * main - function simple shell
 *
 *
 */

int main(void)
{
	char *line;
	int n;
	pid_t child;
	char *list;
	char *argv[];

	while (1)
	{
		signal(SIGINT, Crtlc);
		if(isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		line = line1();
		list = strtok(line, SEP);
		argv[] = {NULL};
		printf("%s\n", line);
		child = fork();
		if (child == -1)
			return (0);
		if(child == 0)
		{
			 if (execve(list, argv, NULL) == -1)
				 perror("Error:");
		}
		else
			wait(&n);
	}
	return (0);
}
