#include "shell.h"
/**
 * execute_command - executes the command
 * @args: arguments
 * @program: points to the program
 * Return: returns argumrnt
 */
void execute_command(char **args)
{
	pid_t pid_child;
	int j;
	char *error_msg;

	if (args[0] != NULL && strcmp(args[0], "exit") == 0)
	{
		for (j = 0; args[j] != NULL; j++)
		{
			free(args[j]);
		}
		free(args);
		exit(0);
	}
	pid_child = fork();

	if (pid_child == -1)
	{
		s_error("forking error\n");
		exit(1);
	}
	else if (pid_child == 0)
	{
		if(execvp(args[0], args) == -1)
		{
			error_msg = malloc(strlen(args[0]) + 30);
			sprintf(error_msg, "%s: 1: %s: not found\n", args[0], args[0]);
			show_print(error_msg);
			free(error_msg);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}
