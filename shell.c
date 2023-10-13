#include "shell.h"
#include <stdio.h>

/**
 * check_input - check if input isn't spaces only
 * @s: string holding input
 * Return: 1 or 0
 */

int check_input(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] > 32)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_input - gets input without \n
 * @s: input from getline
 * Return: new input
 */

char *get_input(char *s)
{
	char *str;
	int len = 0;
	int i = 0;

	while (s[len] && s[len] != '\n')
		len++;
	str = malloc(len + 1);
	if (!str)
		return (0);
	while (s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * check_exit - check if the command is exit
 * @input: string holding command
 * Return: 1 or 0
 */

int check_exit(char *input)
{
	char **s;

	s = split_string(input, ' ');
	if (!ft_strcmp("exit", s[0]))
	{
		s = free_all(s, len_calc(s));
		return (1);
	}
	s = free_all(s, len_calc(s));
	return (0);
}

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
	char *input2;
	size_t len = 0;
	size_t n = 0;
	env_t *p;

	(void)ac;
	(void)av;
	set_env(envp, &p);
	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);
		n = getline(&input, &len, stdin);
		if (n == (size_t)-1)
		{
			free_list_env(p);
			free(input);
			exit(0);
		}
		if (check_input(input))
		{
			input2 = get_input(input);
			if (check_exit(input2))
			{
				free(input2);
				free(input);
				free_list_env(p);
				exit(0);
			}
			check_command(input2, p, envp);
			free(input2);
		}
	}
	return (0);
}
