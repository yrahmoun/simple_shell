#include "shell.h"
#include <stdio.h>

/**
 * main - simple shell program
 * @ac: number of arguments
 * @av: arguments
 * @envp: environment variables
 * Return: 0
 */

int main(int ac, char **av, char **envp)
{
	char *input = NULL;
	size_t len = 0;
	size_t n = 0;
	env_t *p;

	(void)ac;
	(void)av;
	set_env(envp, &p);
	while (1)
	{
		write(1, "$ ", 2);
		n = getline(&input, &len, stdin);
		if (n == (size_t)-1)
		{
			free_list_env(p);
			exit(0);
		}
		if (n > 0 && input[n - 1] == '\n')
			input[n - 1] = '\0';
		check_command(input, p, envp);
		free(input);
	}
	return (0);
}
