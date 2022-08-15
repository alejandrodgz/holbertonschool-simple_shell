#include "main.h"

char **token1(char *line, char* sep, char **list)
{
	int i;
	char *token;

	i = 0;
	token = strtok(line, sep);
	while (token != NULL)
	{
		list[i] = token;
		token = strtok(NULL, sep);
		i++;
	}
	list[i] = NULL;
	i = 0;
	return (list);
}

char **getpath(char **pathlist)
{
	int i = 0;
	char *env;
	char *tokenv;
	char *copy;

	env = getenv("PATH");
	copy = strdup(env);
	tokenv = strtok(copy, ":");
	while (tokenv != NULL)
	{
		pathlist[i] = tokenv;
		tokenv = strtok(NULL,":");
		i++;
	}
	pathlist[i] = NULL;
	return(pathlist);

}

int strlen1(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void conca1(char *path, char *command, char *listpath)
{
	int i =0, j = 0;

	while (path[i] != '\0')
	{
		listpath[i] = path[i];
		i++;
	}
	listpath[i] = '/';
	i++;
	while (command[j] != '\0')
	{
		listpath[i] = command[j];
		i++;
		j++;
	}
	listpath[i] = '\0';
}

void Crtlc(int a)
{
	(void) a;
	write(STDOUT_FILENO, "\n$", 3);
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
        }
	return(line);
}

char *pathex(char **pathlist, char *command, char *fullpath)
{
	int i = 0, s;
	struct stat st;

	while (pathlist[i] != NULL)
	{
		fullpath = malloc(sizeof(char) * (strlen1(pathlist[i])) +
				  (strlen1(command)));
		conca1(pathlist[i], command, fullpath);
		printf("fullpath %s", fullpath);
		if ((s = stat(fullpath, &st)) == 0)
		{
			printf("%d FOUND\n", s);
			return(fullpath);
		}
		else
		{
			printf(" NOT FOUND\n");
		}
			free(fullpath);
			i++;
	}
	return (NULL);
}
