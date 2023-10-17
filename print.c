#include "shell.h"

/**
 * _putchar - print a character
 * @c: character to print
 */

void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

/**
 * print_string - print a string
 * @s: string to print
 */

void print_string(char *s)
{
	int i = 0;

	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
}
