#include "shell.h"
/**
 *execute_cmd -funtion that executes command
 *@exe: executable file path
 *@argv: argument vector
 *@ev: environemnt and it's variables
 * Return: returns 0 or -1
 */
int execute_cmd(char *exe, char **argv, char **ev)
{
	pid_t pid_child;
	int view, res = 0;

	pid_child = fork();
	if (pid_child == -1)
	{
		perror("Fork failed\n");
		res = -1;
	}
	if (pid_child == 0)
	{
		res = execve(ex, argv, ev);
	}
	else
	{
		wait(&view);
	}
	return (res);
}
