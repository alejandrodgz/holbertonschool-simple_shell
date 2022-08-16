#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
/**
 * main - displayed again each time a command has been executed
 */

int main(void)
{
	char *buff = NULL, *argv[1024];
	int flag = 1, err_quot = 0;
	int status_command = EXIT_SUCCESS;

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
		_non_interactive(built_in_array);
	}

	(void)signal(SIGINT, sign_handler);
	(void) built_in_array;
	while (flag)
	{
		_puts("$ ");
		err_quot++;
		buff = line1();
		token1(buff, SEP, argv);
		status_command = shell_executable(argv, built_in_array);
		Error_handler(&status_command, err_quot, argv);
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
