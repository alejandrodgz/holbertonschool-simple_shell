#include "shell.h"
/**
 * _non_interactive - executes the shell in non-interactive mode
 * @arr: array of structures to handle built in commands
 *
 * Return: Nothing
 */
void _non_interactive(builts_in_t arr[], int status)
{
	char **argv;
	char *buff = 0;
	size_t size_buffer = 1024;
	int err_quot = 0;

	while (getline(&buff, &size_buffer, stdin) != EOF)
	{
		err_quot++;
		argv = token_buffer(buff, " \t\r\n\a");
		status = shell_executable(argv, arr, status);
		Error_handler(&status, err_quot, argv);
		free(argv);
	}
	free(buff);
	exit(status);
}
