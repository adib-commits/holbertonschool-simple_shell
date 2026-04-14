#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void run_shell(void);

char **split_line(char *line);
void free_array(char **array);

int execute(char **args);

char *find_in_path(char *command);
int file_exists(char *path);

char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void print_env(void);

void print_error(char *program, char *command);

#endif