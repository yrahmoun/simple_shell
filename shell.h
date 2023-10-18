#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

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

/**
 * struct com_s - struct holding variables
 * @program_name: name of the executable
 * @command_index: number of command executed
 * @status: exit status
 */

typedef struct com_s
{
	char *program_name;
	int command_index;
	int status;
} com_t;

void print_string(char *s);
void _putchar(char c);
void set_env(char **envp, env_t **p);
char *ft_strdup(char *s);
void add_node_end(char *str, env_t **root);
void free_list_env(env_t *head);
char *ft_substr(char *s, int start, int end);
void check_command(char *input, env_t *p, com_t *var);
int ft_strcmp(char *s1, char *s2);
char *join_string(char *s1, char *s2);
char **split_string(char *s, char c);
char **split_space(char *s);
int len_calc(char **s);
char **free_all(char **str, int i);
int check_if_builtin(char *s, env_t *p);
char *ft_itoa(int n);
void print_error(char *name, com_t *var);
void print_env(env_t *p);
int ft_strlen(char *s);

#endif
