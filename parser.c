#include "shell.h"

#define TOKEN_DELIMITERS " \t\r\n\a"
#define BUFFER_SIZE 64

/**
 * split_line - Cut a line into a word table
 * @line: The line to cut
 *
 * Return : Array of strings (argv), NULL if error
 */
char **split_line(char *line)
{
	int bufsize = BUFFER_SIZE;
	int i = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(line, TOKEN_DELIMITERS);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("realloc");
				return (NULL);
			}
		}
		token = strtok(NULL, TOKEN_DELIMITERS);
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * free_array - Release a chain table
 * @array: The table to be released
 */
void free_array(char **array)
{
	if (array)
		free(array);
}
