#include "shell.h"

/**
 * find_len - find length of array to put number in
 * @n: number
 * Return: length
 */

int find_len(int n)
{
	int len = 0;

	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * ft_itoa - turn a number to a char
 * @n: number
 * Return: string holding number
 */

char *ft_itoa(int n)
{
	char *s;
	int len = 0;

	len = find_len(n);
	s = malloc(len + 1);
	if (!s)
		return (0);
	s[len] = '\0';
	len--;
	while (len >= 0)
	{
		s[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (s);
}
