#include "shell.h"

/**
 * totlen2 - finds the number of sub strings to split
 * @s: main string
 * Return: number of sub strings
 */

int totlen2(char *s)
{
	int i = 0;
	int n = 0;

	while (s[i])
	{
		if (s[i] > 32 && (s[i + 1] <= 32 || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

/**
 * string_size2 - counts length of substring
 * @s: main string
 * Return: length
 */

int string_size2(char *s)
{
	int i = 0;

	while (s[i] && s[i] > 32)
		i++;
	return (i);
}

/**
 * fill2 - fills the allocated substrings
 * @s: main string
 * @len: length of substring
 * @str: double pointer holding the substrings
 * Return: str
 */

char **fill2(char *s, int len, char **str)
{
	int i = 0;
	int j;
	int n;

	while (i < len)
	{
		while (*s <= 32)
			s++;
		n = string_size2(s);
		str[i] = malloc(n + 1);
		if (!str[i])
			return (free_all(str, i - 1));
		j = 0;
		while (j < n)
		{
			str[i][j] = *s;
			s++;
			j++;
		}
		str[i][j] = '\0';
		i++;
	}
	str[i] = 0;
	return (str);
}

/**
 * split_space - splits a string into substrings
 * @s: main string
 * Return: double pointer holding the substrings
 */

char **split_space(char *s)
{
	int len;
	char **str;

	len = totlen2(s);
	str = malloc((len + 1) * sizeof(char *));
	if (!str)
		return (0);
	str = fill2(s, len, str);
	return (str);
}
