#include "shell.h"

void remove_trailing_spaces(char *str)
{
    size_t len = _strlen(str);
    if (len > 0)
    {
        while (len > 0 && str[len - 1] == ' ')
        {
            len--;
        }
        str[len] = '\0';
    }
}

void tokenize(char *command, char *argv[MAX_ARGS])
{
    char *token;
    int i = 0;

    token = strtok(command, " ");
    while (token != NULL) {
        argv[i++] = token;
        token = strtok(NULL, " ");
    }
    argv[i] = NULL;
}
int num_args(char *argv[])
{
    int i = 0;
    while (argv[i] != NULL)
    {
        i++;
    }
    return (i);
}
int has_equal(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '=')
        {
            return (1);
        }
        i++;
    }
    return (0);
}