#ifndef SHELL_H
#define SHELL_H

/** Headers **/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>

/** Macros **/
#define BUFFER_SIZE 1024
#define MAX_ARGS 1024
extern char **environ;

/** Function Prototypes **/
char *_getline();
void hash_handler(char *buff);
int _strcmp(const char *str1, const char *str2);
int _strlen(char *str);
int _strncpy(char *dest, char *src, int size);
void *_memcpy(void *dest, void *src, size_t n);
void *_realloc(void *ptr, size_t size);
char *which(char *command);
char *_strtok(char *str, char const *delim);
char *_getenv(char *str);
int _strncmp(const char *str1, const char *str2, size_t len);
int _strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(char *s);
void remove_trailing_spaces(char *str);
void tokenize(char *command, char *argv[MAX_ARGS]);
int num_args(char *argv[]);
int has_equal(char *str);
void _exec(char **_argum, char *av);

/**structures*/
typedef struct  alias_s
{
	char *name;
	char *alias_cmd;
} alias_t;


int alias_command(char *argv[MAX_ARGS], int num_arg);

#endif
