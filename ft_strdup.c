#include "shell.h"

/**
 * ft_strdup - duplicates string and allocates it in memory
 * @s: string to duplicate
 * Return: duplicated string
 */

char *ft_strdup(char *s)
{
	int len = 0;
	int i = 0;
	char *str;

	while (s[len])
		len++;
	str = malloc(len + 1);
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
