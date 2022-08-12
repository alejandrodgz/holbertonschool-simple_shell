#include "main.h"

/**
 *
 *
 *
 */

int main (void)
{
	char *line;
	char *tpath;
	char *tpath1;
	char *list[1024];
	char *pathlist[1024];
	pid_t child;
	int status;
	char *command;
	char **env;

	while (1)
	{
		signal(SIGINT, Crtlc);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, PROMPT, 1);
		line = line1();
		token1(line, SEP, list);
		command = list[0];
		getpath(pathlist);
		tpath1 = pathex(pathlist, command, tpath);
		child = fork();
		if (child == -1)
			return (0);
		if (child == 0)
		{
			if(execve(tpath1, list, env) == -1)
				free(tpath1);
				return(0);
		}
		else
			wait(&status);
	}
	return (0);
}
