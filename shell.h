#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct env_s - linked list containing environment variables
 * @str: string holding a variable
 * @next: pointer to next node
 */

typedef struct env_s
{
	char *str;
	struct env_s *next;
} env_t;

void print_string(char *s);
void set_env(char **envp, env_t **p);
char *ft_strdup(char *s);
void add_node_end(char *str, env_t **root);
void free_list_env(env_t *head);

#endif
