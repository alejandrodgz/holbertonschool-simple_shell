#ifndef MAIN_H
#define MAIN_H
#define SEP " \t\r\n\v\f"
#define PROMPT "$"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

char *getln(void);

char **token1(char *line, char* sep, char **list);

char **getpath(char **pathlist);

int strlen1(char *str);

void conca1(char *path, char *command, char *listpath);

char *pathex(char **pathlist, char *command, char *fullpath);

void Crtlc(int a);

char *line1(void);

#endif /*MAIN_H*/
