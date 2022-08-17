#include "shell.h"

/**
 * shell_executable - executes the built in commands
 * @argv: pointer to the argv
 * @built_arr: pointer to the struct with built in comm
 * Return: 1 on success
 **/

int shell_executable(char **argv, builts_in_t built_arr[], int status_command)
{
	int a = 0;

	if (argv[0] == NULL)
		return (0);

	while (a < 5)
	{
		if (_str_comparation(argv[0], built_arr[a].name_command) == 0)
		{
			return (built_arr[a].f(argv, status_command));
		}
		a++;
	}
	return (shell_launch(argv));
}



/**
 * shell_launch - creates the process to execute shell commands
 * @argv: pointer to argv
 * Return: 1 on success
 */
int shell_launch(char **argv)
{
	int pid, existence, tmp_path = 0, c, status;
	char **path = 0, *command = 0, *path_command = 0, *env = 0;

	pid = fork();
	if (pid == 0)
	{
		env = _get_enviro("PATH");
		if (env && env[0] == ':')
			tmp_path = 1;
		path = token_buffer(env, ":");
		for (c = 0; path[c]; c++)
		{
			command = _string_cat("/", argv[0]);
			path_command = _string_cat(path[c], command);
			existence = checker_existence(path_command);
			if (existence != -1 && !tmp_path)
			{
				argv[0] = path_command;
				break;
			}
			else
				free(path_command);
			free(command);
		}
		existence = checker_existence(argv[0]);
		if (existence == -1)
		{
			_free(argv, path);
			exit(127);
		}
		if (execve(argv[0], argv, environ) == -1)
			perror("Error");
		_free(argv, path);
		exit(2);
	}
	else if (pid < 0)
		perror("hsh");
	else
		wait(&status);
	return (WEXITSTATUS(status));
}

/**
 * _free - frees argv and path
 * @argv: buff containing the tokens
 * @path: path to look for exec files
 * Return - Nothing
 */

void _free(char **argv, char **path)
{
	free(argv[0]);
	free(argv);
	free(path);
}

/**
 * checker_existence - checkes the exist's file
 * @path: pointer to the path to search
 *
 * Return: 1 if works, -1 if fails
 */

int checker_existence(char *path)
{
	int fd = access(path, F_OK | X_OK);

	if (fd == -1)
	{
		return (-1);
	}
	return (1);
}
