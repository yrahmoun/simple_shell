#include "shell.h"

/**
 * len_calc - find size of a double pointer
 * @s: double pointer
 * Return: size
 */

int len_calc(char **s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}
