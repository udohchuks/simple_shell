#include "shell.h"
 /*struct Node *head = NULL;*/
/* print the contents of the linked list */
void print_list(struct Node *head)
{
  while (head != NULL) {
    write(STDOUT_FILENO, head->str, _strlen(head->str));
    write(STDOUT_FILENO, "\n", 1);
    head = head->next;
  }
}
/* free up memory allocated for each node in the linked list */
void free_list(struct Node *head)
{
  struct Node *temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}
int _env()
{
	char **env;
  /* get the environment variable */
  extern char **environ;

  /* create a linked list of the environment variable */
  struct Node *head = NULL;
  for (env = environ; *env != NULL; env++) {
    add_node(&head, new_node(*env));
  }

  /* print the linked list */
  print_list(head);

  /* free up memory allocated for each node in the linked list */
  free_list(head);
  return 0;
}

/*Setenv */
int _setenv(const char *name, const char *value)
{
	char **env;
  /* get the environment variable */
  extern char **environ;

  /* create a linked list of the environment variable */
  struct Node *head = NULL;
  for (env = environ; *env != NULL; env++) {
    add_node(&head, new_node(*env));
  }

  /* Setenv */
  add_env_var(&head, name, value);
  /* update the environ variable */
  update_environ(head);

  /* free up memory allocated for each node in the linked list */
  free_list(head);
  return 0;
}
/* delete an environment variable */
int _unsetenv(const char *name)
{
  extern char **environ;
  char **e;
  char **env;
  size_t len = _strlen(name);

  for (env = environ; *env != NULL; env++) {
    if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=') {
      for (e = env; *e != NULL; e++) {
        *e = *(e + 1);
      }
      return 0;
    }
  }
  return -1;
}
/* add a new environment variable to the linked list */
void add_env_var(struct Node **head, const char *name, const char *value)
{
  size_t name_len = _strlen(name);
  size_t value_len = _strlen(value);
  char *new_env_var = malloc(name_len + value_len + 2);
  struct Node *current;
  if (new_env_var == NULL) {
    return;
  }

  _memcpy(new_env_var, (void *)name, name_len);
  new_env_var[name_len] = '=';
  _memcpy(new_env_var + name_len + 1, (void *)value, value_len);
  new_env_var[name_len + value_len + 1] = '\0';
  /* search for an existing environment variable with the same name */
  current = *head;
  while (current != NULL)
  {
    if (_strncmp(current->str, name, name_len) == 0 && current->str[name_len] == '=') {
      /* found an existing environment variable with the same name */
      /* free(current->str); */
      current->str = new_env_var;
      return;
    }
    current = current->next;
  }
  /*not found existing environment variable*/
  add_node(head, new_node(new_env_var));
}

void update_environ(struct Node *head)
{
  /* count the number of nodes in the linked list */
  size_t count = 0;
  size_t i;
  struct Node *current = head;
  char **new_environ;

  while (current != NULL) {
    count++;
    current = current->next;
  }
  /* allocate memory for a new environ array */
  new_environ = malloc((count + 1) * sizeof(char *));
  if (new_environ == NULL) {
    return;
  }

  /* copy the environment variables from the linked list to the new environ array */
  current = head;
  for (i = 0; i < count; i++) {
    new_environ[i] = current->str;
    current = current->next;
  }
  new_environ[count] = NULL;
  /* update the environ variable */
  environ = new_environ;
}