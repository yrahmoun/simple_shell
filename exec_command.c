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
 * check_exist - check if command exists
 * @str: pointer to command
 * @path: pointer to path values
 * Return: str
 */

char **check_exist(char **str, char **path)
{
	int i = 0;
	int x = 0;
	char *tmp;
	struct stat s;

	while (str[0][x])
	{
		if (str[0][x] == '/')
		{
			if ((stat(str[0], &s) == 0))
			{
				return (str);
			}
			else
			{
				free(str[0]);
				str[0] = ft_strdup("null");
				return (str);
			}
		}
		x++;
	}
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
	str[0] = ft_strdup("null");
	return (str);
}

/**
 * exec_command - executes a command
 * @str: double pointer holding command to execute
 * @path: double pointer holding path values
 * @var: pointer to struct
 * Return: str
 */

char **exec_command(char **str, char **path, com_t *var)
{
	int pid;
	int status;
	char *original_command;

	original_command = ft_strdup(str[0]);
	str = check_exist(str, path);
	if (!ft_strcmp(str[0], "null"))
	{
		print_error(original_command, var);
		free(original_command);
		var->status = 127;
		return (str);
	}
	free(original_command);
	pid = fork();
	if (pid == 0)
	{
		if ((execve(str[0], str, environ) == -1))
		{
			perror(var->program_name);
			exit(127);
		}
	}
	waitpid(pid, &status, 0);
	var->status = WEXITSTATUS(status);
	return (str);
}

/**
 * set_path - extract the PATH
 * @p: pointer to linked list hold env variables
 * Return: PATH variable value split into substrings
 */

char **set_path(env_t *p)
{
	env_t *curr = p;

	while (curr)
	{
		if (!ft_strcmp(curr->name, "PATH"))
			return (split_string(curr->value, ':'));
		curr = curr->next;
	}
	return (0);
}

/**
 * check_command - check if a command is a built-in
 * @input: string holding command
 * @p: pointer to env variable list
 * @var: pointer to struct
 */

void check_command(char *input, env_t *p, com_t *var)
{
	char **str;
	char **path;

	str = split_space(input);
	path = set_path(p);
	str = exec_command(str, path, var);
	str = free_all(str, len_calc(str));
	path = free_all(path, len_calc(path));

}
