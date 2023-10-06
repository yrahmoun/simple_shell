#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct env_s - linked list containing environment variables
 * @str: string holding a variable
 * @name: env variable name
 * @value: env variable value
 * @next: pointer to next node
 */

typedef struct env_s
{
	char *str;
	char *name;
	char *value;
	struct env_s *next;
} env_t;

void print_string(char *s);
void set_env(char **envp, env_t **p);
char *ft_strdup(char *s);
void add_node_end(char *str, env_t **root);
void free_list_env(env_t *head);
char *ft_substr(char *s, int start, int end);
void check_command(char *input, env_t *p, char **envp);
int ft_strcmp(char *s1, char *s2);
char *join_string(char *s1, char *s2);
char **split_string(char *s, char c);
int len_calc(char **s);
char **free_all(char **str, int i);

#endif
