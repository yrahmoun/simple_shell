#include "shell.h"

/**
 * join_string - concatinate two strings
 * @s1: string 1
 * @s2: string 2
 * Return: concatinated string
 */

char *join_string(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int len1 = 0;
	int len2 = 0;
	char *str;

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
