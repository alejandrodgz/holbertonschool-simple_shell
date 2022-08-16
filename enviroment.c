#include "shell.h"

/**
 * _get_enviro - gets the environ variable
 * @name: name of the env variabl to look for
 * Return: pointer to the env variable
 **/

char *_get_enviro(char *name)
{
	int a = 0;
	char *token, *delimit = "=";
	char *dup;

	while (environ[a] != NULL)
	{
		dup = _string_dup(environ[a]);
		token = _token_string(environ[a], delimit);
		if (_str_comparation(token, name) == 0)
		{
			token = _token_string(NULL, delimit);
			environ[a] = _str_copy(environ[a], dup);
			free(dup);
			return (token);
		}
		environ[a] = _str_copy(environ[a], dup);
		free(dup);
		a++;
	}
	return (0);
}

/**
 * _print_enviro - prints the enviroment
 * @argv: pointer to the commands
 * Return: 1 on success
 */

int _print_enviro(char **argv)
{
	int a;
	(void) argv;

	for (a = 0; environ[a] != NULL; a++)
	{
		_puts(environ[a]);
		_puts("\n");
	}
	return (0);
}

/**
 * _set_environ - sets a new enviromental variable
 * @argv: pointer to the input commands
 * Return: 1 on success
 */

int _set_environ(char **argv)
{
	int status = EXIT_SUCCESS, exist = 0, a = 0;
	char *dup = 0, *token = 0, *valg = 0;

	while (environ[a])
	{
		dup = _string_dup(environ[a]);
		token = _token_string(dup, "=");
		if (!_str_comparation(token, argv[1]))
		{
			token = _string_cat(argv[1], "=");
			valg = _string_cat(token, argv[2]);
			environ[a] = _str_copy(environ[a], valg);
			free(token);
			free(valg);
			exist = 1;
		}
		free(dup);
		a++;
	}
	if (exist == '\0')
	{
		return ('\0');
	}
	return (status);
}

/**
 * _unset_environ - unsets an enviromental var
 * @argv: pointer to the buffer with the command line
 * Return: 1 on success
 */

int _unset_environ(char **argv)
{
	int a = 0, exist = 0, lenght = 0, b = 0;
	char *token, *copy;
	char **new_enviro;

	while (environ[a])
	{
		copy = _string_dup(environ[a]);
		token = _token_string(copy, "=");
		if (!_str_comparation(token, argv[a]))
		{
			exist = 1;
		}
		lenght++;
		a++;
		free(copy);
	}
	if (exist)
	{
		new_enviro = malloc(sizeof(char *) * (lenght - 1));
		for (a = 0; a < lenght; a++)
		{
			copy = _string_dup(environ[a]);
			token = _token_string(copy, "=");
			if (!_str_comparation(token, argv[a]))
			{
				printf("----------> Removing: %s\n", environ[a]);
				continue;
			}
			new_enviro[b] = environ[a];
			b++;
		}
		new_enviro[lenght - 1] = NULL;
		environ = new_enviro;
	}
	return (1);
}
