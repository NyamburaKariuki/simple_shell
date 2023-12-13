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

	pid_child = fork();

	if (pid_child == -1)
	{
		show_print("forking error\n");
		exit(1);
	}
	else if (pid_child == 0)
	{
		execvp(args[0], args);
		show_print("%s: command not found\n", args[0]);
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
