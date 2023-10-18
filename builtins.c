#include "shell.h"

/**
 * check_env - checks if the command is env
 * @str: string holding command
 * Return: 1 or 0
 */

int check_env(char *str)
{
	char **s;

	s = split_space(str);
	if (!ft_strcmp("env", s[0]))
	{
		s = free_all(s, len_calc(s));
		return (1);
	}
	s = free_all(s, len_calc(s));
	return (0);
}

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
