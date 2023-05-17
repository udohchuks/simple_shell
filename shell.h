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

/** Macros **/
#define BUFFER_SIZE 1024
extern char **environ;

/** Function Prototypes **/
char *_getline();
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



#endif
