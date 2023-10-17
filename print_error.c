#include "shell.h"

/**
 * ft_strlen - find length of a string
 * @s: string
 * Return: length
 */

int ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * print_error - prints an error message
 * @name: name of command that doesn't exist
 * @var: pointer to struct
 */

void print_error(char *name, com_t *var)
{
	char message[] = ": not found\n";
	char *num;

	num = ft_itoa(var->command_index);
	write(STDERR_FILENO, var->program_name,
			ft_strlen(var->program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num, ft_strlen(num));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, name, ft_strlen(name));
	write(STDERR_FILENO, message, ft_strlen(message));
	free(num);
}
