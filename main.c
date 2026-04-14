#include "shell.h"

/**
 * main - Shell entry point
 *
 * Return : Always 0.
 */
int main(void)
{
	run_shell();
	return (0);
}
 
/**
 * run_shell - main shell loop
 * displays the prompt, reads the command, executes it, and repeats
 */
void run_shell(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
 
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(line);
			break;
		}
 
		if (nread == 1 && line[0] == '\n')
			continue;

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		args = split_line(line);
		if (args == NULL || args[0] == NULL)
		{
			free_array(args);
			continue;
		}

		execute(args);

		free_array(args);
	}
}
