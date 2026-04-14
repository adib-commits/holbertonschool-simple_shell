#include "shell.h"

/**
 * print_error - Displays a formatted error message
 * @program: name of the shell
 * @command: Command not found
 */
void print_error(char *program, char *command)
{
	write(STDERR_FILENO, program, strlen(program));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, ": command not found\n", 23);
}
