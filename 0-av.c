#include <stdio.h>

/**
 * main - prints all arguments without using ac
 * @ac: argument count (unused)
 * @av: argument vector
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
int i = 0;

(void)ac;

while (av[i] != NULL)
{
printf("%s\n", av[i]);
i++;
}

return (0);
}
