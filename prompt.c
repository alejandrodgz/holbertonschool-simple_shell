#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - displayed again each time a command has been executed
 * Return: Succesfull 0
 */

int main(void)
{
	char *buff = NULL, **argv = NULL, **argv_non;
	int flag = 1, err_quot = 0, err_count_non = 0;
	int status_command = EXIT_SUCCESS;
	size_t size_buffer = 1024;

/*Here are the function who are gonna have the commands of the shell*/
	builts_in_t built_in_array[] = {
		{"exit", our_exit},
		{"env", _print_enviro},
		{"unsetenv", _unset_environ},
		{"cd", _cd},
		{NULL, NULL}
	};

	if (isatty(STDIN_FILENO) != 1)
	{
		while (getline(&buff, &size_buffer, stdin) != EOF)
		{
			err_count_non++;
			argv_non = token_buffer(buff, " \t\r\n\a");
			status_command = shell_executable(argv_non, built_in_array, status_command);
			Error_handler(&status_command, err_count_non, argv_non);
			free(argv_non);
		}
		free(buff);
		exit(status_command);
	}

	(void)signal(SIGINT, sign_handler);
	(void) built_in_array;
	while (flag)
	{
		_puts("$ ");
		err_quot++;
		buff = read_input();
		argv = token_buffer(buff, " \t\r\n\a");
		status_command = shell_executable(argv, built_in_array, status_command);

		Error_handler(&status_command, err_quot, argv);
		free(argv);
		free(buff);
	}
	return (status_command);
}

/**
 * read_input - read input form stdin
 * Return: pointer to buffer read
 */

char *read_input()
{
	char *buffer = NULL;
	size_t size_buff = 1024;

	if (getline(&buffer, &size_buff, stdin) == EOF)
	{
		_puts("\n");
		free(buffer);
		exit(127);
	}
	buffer[_str_lenght(buffer) - 1] = '\0';
	return (buffer);
}

/**
 * sign_handler - handles the abscensce of a sign
 * @sig: integer
 */

void sign_handler(int sig)
{
	(void) sig;
	_puts("\n");
	_puts("S ");
	fflush(stdout);
}
