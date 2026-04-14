#include "shell.h"

/**
 * file_exists - Checks if a file exists and is executable
 * @path: The path of the file
 *
 * Return: 1 if found, 0 otherwise
 */
int file_exists(char *path)
{
	struct stat st;

	if (stat(path, &st) == 0)
		return (1);
	return (0);
}

/**
 * find_in_path - Looking for a command in the PATH directories
 * @command: The name of the command
 *
 * Return: full path if found, NULL otherwise
 */
char *find_in_path(char *command)
{
	char *path_env;
	char *path_copy;
	char *dir;
	char *full_path;
	size_t len;

	if (command[0] == '/' || command[0] == '.')
	{
		if (file_exists(command))
			return (strdup(command));
		return (NULL);
	}

	path_env = _getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		len = strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);

		if (file_exists(full_path))
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
