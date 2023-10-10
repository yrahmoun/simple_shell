#include "shell.h"

/**
 * print_env - prints the env variables
 * @p: pointer to env list
 * Return: 1
 */

int print_env(env_t *p)
{
	env_t *curr;

	curr = p;
	while (curr)
	{
		print_string(curr->str);
		_putchar('\n');
		curr = curr->next;
	}
	return (1);
}

/**
 * check_if_builtin - check if command is a builtin
 * @s: string holding command to check
 * @p: pointer to env variables list
 * Return: 1 or 0
 */

int check_if_builtin(char *s, env_t *p)
{
	if (!ft_strcmp(s, "env"))
		return (print_env(p));
	return (0);
}
