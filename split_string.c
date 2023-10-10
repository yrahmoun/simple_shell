#include "shell.h"

/**
 * totlen - finds the number of sub strings to split
 * @s: main string
 * @c: separator
 * Return: number of sub strings
 */

int totlen(char *s, char c)
{
	int i = 0;
	int n = 0;

	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

/**
 * string_size - counts length of substring
 * @s: main string
 * @c: separator
 * Return: length
 */

int string_size(char *s, char c)
{
	int i = 0;

	while (s[i] && s[i] != c)
		i++;
	return (i);
}

/**
 * free_all - frees the substring double pointer
 * @str: substring double pointer
 * @i: current index
 * Return: 0
 */

char **free_all(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

/**
 * fill - fills the allocated substrings
 * @s: main string
 * @c: separator
 * @len: length of substring
 * @str: double pointer holding the substrings
 * Return: str
 */

char **fill(char *s, char c, int len, char **str)
{
	int i = 0;
	int j;
	int n;

	while (i < len)
	{
		while (*s == c)
			s++;
		n = string_size(s, c);
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
 * split_string - splits a string into substrings
 * @s: main string
 * @c: separator
 * Return: double pointer holding the substrings
 */

char **split_string(char *s, char c)
{
	int len;
	char **str;

	len = totlen(s, c);
	str = malloc((len + 1) * sizeof(char *));
	if (!str)
		return (0);
	str = fill(s, c, len, str);
	return (str);
}
