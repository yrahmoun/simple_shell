#include "shell.h"

/**
 * ft_substr - extratcs a portion of a string
 * @s: string to extract from
 * @start: index of start of portion
 * @end: index of end of portion
 * Return: sub string
 */

char *ft_substr(char *s, int start, int end)
{
	char *str;
	int i = 0;

	str = malloc(end - start + 1);
	if (!str)
		return (0);
	while (start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
