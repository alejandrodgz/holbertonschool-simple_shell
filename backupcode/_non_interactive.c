#include "shell.h"
/**
 * _non_interactive - executes the shell in non-interactive mode
 * @arr: array of structures to handle built in commands
 *
 * Return: Nothing
 */
void _non_interactive(builts_in_t arr[])
{
	char **argv;
	char *buff = 0;
	int status = EXIT_SUCCESS;
	size_t size_buffer = 1024;
	int err_quot = 0;

	while (getline(&buff, &size_buffer, stdin) != EOF)
	{
		err_quot++;
		argv = token_buffer(buff, " \t\r\n\a");
		status = shell_executable(argv, arr);
		Error_handler(&status, err_quot, argv);
		free(argv);
	}
	free(buff);
	exit(status);
}

char *line1(void)
{
	char *line = NULL;
	size_t n;
	int h;

	h = getline(&line, &n, stdin);
	if (h == -1)
	{
		free(line);
		line1();
	}
	return(line);
}