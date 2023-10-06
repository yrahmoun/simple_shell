#include "shell.h"

/**
 * ft_strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: difference at first character different
 */

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && (s1[i] == s2[i]))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
