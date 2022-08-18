#ifndef SHELL_H
#define SHELL_H
extern char **environ;
extern char *program_invocation_name;
/*#define SEP ' \t\r\n\v\f'*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
/*Structs*/

/**
 * struct builts - struct for the built-in functions
 * @name_command: name of the built-in
 * @f: function fpor corresponding built-in
 */

typedef struct builts
{
	char *name_command;
	int (*f)(char **argv, int status);
} builts_in_t;

/*Prototypes*/

void _puts(char *s);
int _putchar(const char c);
int _putchar1(const char c);
void _printd(int num);
void _printd1(int num);
char *_token_string(char *s, char *delimit);
char *strchar(char *s, char b);
unsigned int _strcspn(char *s, char *pre);
char **token_buffer(char *buff, char *delimit);
int _str_lenght(char *s);
char *Read_the_input();
int _str_comparation(char *s1, char *s2);
void _free(char **argv, char **path);
int checker_existence(char *path);
char *_string_cat(char *str1, char *str2);
char *_string_dup(char *string);
char *_str_copy(char *dest, char *src);
char *_get_enviro(char *name);
int shell_launch(char **argv);
int shell_executable(char **argv, builts_in_t built_arr[], int status_command);
void Error_handler(int *status, int err, char **argv);
void _print_error(int err, char **argv);
char *read_input();
void sign_handler(int sig);
int _atoi(char *s);
int _cd(char **argv, int status_command __attribute__((unused)));
int our_exit(char **argv, int status_command);
int _print_enviro(char **argv, int status_command __attribute__((unused)));
int _set_environ(char **argv);
int _unset_environ(char **argv, int status_command __attribute__((unused)));
void _putse(char *s);
void _print_error1(int err, char **argv);
#endif /*SHELL_H*/
