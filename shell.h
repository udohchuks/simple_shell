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
#include <signal.h>

/** Macros **/
#define BUFFER_SIZE 1024
#define MAX_ARGS 1024
#define MAX_NUM_Aliases 100
extern char **environ;

/** Function Prototypes **/
char *_getline();
void hash_handler(char *buff);
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
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
void _exec(char **_argum, char *av);
void _1exit(char *status __attribute__((unused)));
int _atoi(const char *str);
/**structures*/
typedef struct  alias_s
{
	char *name;
	char *alias_cmd;
} alias_t;
int alias_command(char *argv[MAX_ARGS], int num_arg);


/* struct Node - singly linked list */
struct Node {
  char *str;
  struct Node *next;
};


/* create a new node in the linked list */
static struct Node *new_node(char *str) __attribute__((unused));
static struct Node *new_node(char *str) {
  struct Node *node = malloc(sizeof(struct Node));
  node->str = str;
  node->next = NULL;
  return node;

}
/* add a node to the end of the linked list */
static void add_node(struct Node **head, struct Node *node) __attribute__((unused));
static void add_node(struct Node **head, struct Node *node) {
  if (*head == NULL) {
    *head = node;
  } else {
    struct Node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = node;
  }
}
void print_list(struct Node *head);
void free_list(struct Node *head);
int _env();
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value);
void add_env_var(struct Node **head, const char *name, const char *value);
void update_environ(struct Node *head);
void handle_segfault(int signo __attribute__((unused)));
void handle_sigint(int signo __attribute__((unused)));
#endif