#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (void)
{
	int i = 0, j = 0;
	char *path;
	char *token;
	char *sep = ":";

	path = getenv("PATH");
	token = strtok(path, sep);
	if (token == NULL)
	{
		printf("error");
		return(-1);
	}
	while (token != NULL)
	{
		printf("token = %s\n", token);
		token = strtok(NULL, sep);
	}
	return (0);
}
