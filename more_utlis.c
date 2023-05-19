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
int _atoi(const char *str)
{
  int i, n = 0;
  int sign = 1;

  for (i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == '-') {
      sign = -1;
    } else if (str[i] >= '0' && str[i] <= '9') {
      n = n * 10 + (str[i] - '0');
    } else {
      break;
    }
  }

  return (n * sign);
}
void _1exit(char *status __attribute__((unused)))
{
    int i = _atoi(status)
    if (status)
    {
    exit(i);
    }
  exit(99);
}
