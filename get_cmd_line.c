#include "shell.h"

/**
 * display_p - displays prompt
 *
 * Return: void
 */
char *display_p(void)
{
	char *buff = malloc(1024);
	ssize_t br;
	pid_t pid_child;


	pid_child = fork();
	if (pid_child == 0)
	{
		printf("($) ");
		exit(0);
	}
	else
	{
		while ((br = read(0, buff, 1023)) != -1)
		{
			return (buff);
		}
		return (NULL);
	}
}
