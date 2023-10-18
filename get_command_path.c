#include "shell.h"

/**
 * replace_input - replaces a relative path with an absolute one
 * @str: string holding command
 * @path: string holding command
 * Return: absolute path to command
 */

char *replace_input(char *str, char *path)
{
	int len1 = 0;
	int len2 = 0;
	int i = 0;
	int j = 0;
	char *command;

	while (str[len1])
		len1++;
	while (path[len2])
		len2++;
	command = malloc(len1 + len2 + 2);
	if (!command)
		return (0);
	while (path[i])
	{
		command[i] = path[i];
		i++;
	}
	command[i] = '/';
	i++;
	while (str[j])
	{
		command[i] = str[j];
		i++;
		j++;
	}
	command[i] = '\0';
	return (command);
}

/**
 * handle_absolute - handles the case of an absolute path
 * @str: double pointer holding command
 * Return: str
 */

char **handle_absolute(char **str)
{
	struct stat s;

	if ((stat(str[0], &s) == 0))
		return (str);
	free(str[0]);
	str[0] = ft_strdup("null");
	return (str);
}

/**
 * case_absolute - checks if command path is absolute
 * @s: string holding command
 * Return: 1 or 0
 */

int case_absolute(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

/**
 * check_exist - check if command exists
 * @str: pointer to command
 * @path: pointer to path values
 * Return: str
 */

char **check_exist(char **str, char **path)
{
	int i = 0;
	char *tmp;
	struct stat s;

	if (case_absolute(str[0]))
		return (handle_absolute(str));
	if (!path)
		free(str[0]);
	else
	{
		tmp = ft_strdup(str[0]);
		free(str[0]);
		while (path[i])
		{
			str[0] = replace_input(tmp, path[i]);
			if (stat(str[0], &s) == 0)
			{
				free(tmp);
				return (str);
			}
			free(str[0]);
			i++;
		}
		free(tmp);
	}
	str[0] = ft_strdup("null");
	return (str);
}
