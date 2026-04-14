#include "shell.h"

/**
 * execute - Fork + execute to execute a command
 * @args: argument array
 *
 * Return: 1 to continue, 0 to quit
 */
int execute(char **args)
{
	pid_t pid;
	int status;
	char *cmd_path;

	if (strcmp(args[0], "exit") == 0)
		exit(0);

	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	cmd_path = find_in_path(args[0]);
	if (cmd_path == NULL)
	{
		print_error("hsh", args[0]);
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return (1);
	}

	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			perror("execve");
			free(cmd_path);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}

	free(cmd_path);
	return (1);
}
