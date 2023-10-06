#include "shell.h"

/**
 * get_var_value - extracts the env variable's value
 * @s: string to extract from
 * Return: env variable value
 */

char *get_var_value(char *s)
{
	int i = 0;
	int len = 0;
	char *value;

	while (s[i] && s[i] != '=')
		i++;
	i++;
	while (s[len])
		len++;
	value = ft_substr(s, i, len);
	return (value);
}

/**
 * get_var_name - extracts the env variable's name
 * @s: string to extract from
 * Return: env variable name
 */

char *get_var_name(char *s)
{
	int len = 0;
	char *name;

	while (s[len] && s[len] != '=')
		len++;
	name = ft_substr(s, 0, len);
	return (name);
}

/**
 * add_node_end - adds node to linked list
 * @str: string containg environment variable
 * @root: pointer to linked list
 */

void add_node_end(char *str, env_t **root)
{
	env_t *curr;
	env_t *new;

	new = malloc(sizeof(env_t));
	if (!new)
		return;
	new->str = ft_strdup(str);
	new->name = get_var_name(str);
	new->value = get_var_value(str);
	new->next = NULL;
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

/**
 * set_head - sets first node of the linked list
 * @str: node content
 * Return: pointer to list
 */

env_t *set_head(char *str)
{
	env_t *p;

	p = malloc(sizeof(env_t));
	if (!p)
		return (0);
	p->str = ft_strdup(str);
	p->name = get_var_name(str);
	p->value = get_var_value(str);
	p->next = NULL;
	return (p);
}

/**
 * set_env - turns **envp into a linked list
 * @envp: double pointer holding environment variables
 * @p: pointer to linked list
 */

void set_env(char **envp, env_t **p)
{
	int i = 1;

	*p = set_head(envp[0]);
	while (envp[i])
	{
		add_node_end(envp[i], p);
		i++;
	}
}
