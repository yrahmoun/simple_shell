#include "shell.h"

/**
 * print_env - prints the env variables
 */

void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], ft_strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
