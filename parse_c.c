#include "shell.h"

/**
 *command_parse - function to parse arguments of a command
 *@status: status
 *Return: Always 0 (Success)
 */

char **command_parse(const char *status)
{
	char **args;
	args = malloc(2 * sizeof(char *));
	args[0] = strdup(status);
	args[1] = NULL;
	return (args);
}
