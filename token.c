#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"



char **token_buffer(char *buff, char *delimit)
{
	int buffsize = 64, iterator = 0;
	char **tokens = malloc(sizeof(char *) * buffsize);
	char *string_token;
	
	if (tokens == NULL)
	{
		perror("Not possible to allocate memory");
		free(buff);
		exit(98);
	}
	string_token = _token_string(buff, delimit);
	while (string_token)
	{
		tokens[iterator] = string_token;
		iterator++;
		string_token = _token_string(NULL, delimit);
	}
	tokens[iterator] = NULL;
	return (tokens);
}




char *Read_the_input()
{
	char *buff = NULL;
	size_t size_buff = 1024;

	if (getline(&buff, &size_buff, stdin) == EOF)
	{
		_puts("\n");
		free(buff);
		exit(127);
	}
	buff[_str_lenght(buff) - 1] = '\0';
	return (buff);
}
	
