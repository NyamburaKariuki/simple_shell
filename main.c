#include "shell.h"
/**
 * main - main entry file
 * @void: has no parameters
 * Return: returns 0
 */
int main(void)
{
	char *status = malloc(120), *str;
	char **args;

	signals();
	while (1)
	{
		show_display();
		str = read_command_display(status, 119);

		if (_strcmp(str, "exit") == 0)
		{
			free(status);
			free(str);
			exit(0);
		}
		args = command_parse(str);
		execute_command(args);
		free(str);
		free(args[0]);
		free(args);
	}
	return (0);
}
