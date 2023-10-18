#include "shell.h"

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
	if (path)
		path = free_all(path, len_calc(path));

}
