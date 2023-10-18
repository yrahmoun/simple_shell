#include "shell.h"

/**
 * print_env - prints the env variables
 * @var: pointer to struct
 */

void print_env(com_t *var)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], ft_strlen(environ[i]));
		if (environ[i + 1] != NULL)
			write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	var->status = 0;
	write(STDOUT_FILENO, "\n", 1);
}
