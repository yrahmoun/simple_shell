#include "shell.h"

/**
 * print_env - prints the env variables
 * @p: pointer to env list
 */

void print_env(env_t *p)
{
	env_t *curr;

	curr = p;
	while (curr)
	{
		write(STDOUT_FILENO, curr->str, ft_strlen(curr->str));
		write(STDOUT_FILENO, "\n", 1);
		curr = curr->next;
	}
}
