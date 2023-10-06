#include "shell.h"

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

	if (str[0][0] == '/')
	{
		if (access(str[0], X_OK) == 0)
			return (str);
	}
	else
	{
		while (path[i])
		{
			tmp = str[0];
			str[0] = join_string("/", str[0]);
			str[0] = join_string(path[i], str[0]);
			if (access(str[0], F_OK) == 0)
				return (str);
			str[0] = tmp;
			i++;
		}
		str[0] = ft_strdup("null");
	}
	return (str);
}

/**
 * exec_command - executes a command
 * @str: double pointer holding command to execute
 * @envp: double pointer holding env variables
 * @path: double pointer holding path values
 */

char **exec_command(char **str, char **envp, char **path)
{
	int pid;
	int status;

	str = check_exist(str, path);
	if (!ft_strcmp(str[0], "null"))
	{
		printf("---not found---\n");
		return (str);
	}
	pid = fork();
	if (pid < 0)
		return (str);
	if (pid == 0)
	{
		if ((execve(str[0], str, envp) == -1))
		{
			perror("command not found");
			exit(-1);
		}
	}
	waitpid(pid, &status, 0);
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
 * @envp: string holding env variables
 */

void check_command(char *input, env_t *p, char **envp)
{
	char **str;
	char **path;

	str = split_string(input, ' ');
	path = set_path(p);
	str = exec_command(str, envp, path);
	str = free_all(str, len_calc(str));
	path = free_all(path, len_calc(path));
}
