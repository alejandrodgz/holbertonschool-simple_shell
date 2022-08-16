#include "shell.h"

/**
 * our_exit - checks whether the input is the exit command
 * @argv: buffer with the commands
 * 
 * Return: Exit status
 */

int our_exit(char **argv)
{
    int status = 0, a;

    if (argv[1] == NULL)
    {
        free(argv[0]);
        free(argv);
        fflush(stdout);
        exit(status);
    }
    for (a = 0; argv[1][a] != '\0'; a++)
    {
        if (argv[1][a] < 48 || argv[1][a] > 57)
        {
            return (3);
        }
    }
    status = _atoi(argv[1]);
    free(argv[0]);
    free(argv);
    exit(status);
}

/**
 * _cd - fuction that cabges the current directory
 * @argv: atring containing the input
 * 
 * Return: 1 if works
 */

int _cd(char **argv)
{
    char buff[1024], *cwd, *new_pwd, *comp = "-", *old_pwd;
    int chint = 0;
    char *env;

    cwd = getcwd(buff, sizeof(buff));
    if (argv[1] == NULL)
    {
        setenv("OLDPWD", getcwd(buff, sizeof(buff)), 1);
        env = _get_enviro("HOME");
        chdir(env);
        return (0);
    }
    if (_str_comparation(argv[1], comp) == 0)
    {
        old_pwd = _get_enviro("OLDPWD");
        setenv("OLDPWD", getcwd(buff, sizeof(buff)), 1);
        chdir(old_pwd);
        return (0);
    }
    if (cwd == NULL)
    {
        free(argv);
        perror("Error: ");
        return (1);
    }
    chint = chdir(argv[1]);

    if (chint == -1)
    {
        free(argv);
        perror("Error: ");
        return(1);
    }
    setenv("OLDPWD", _get_enviro("PWD"), 1);
    new_pwd = getcwd(buff, sizeof(buff));
    setenv("PWD", new_pwd, 1);
    return (0);
}