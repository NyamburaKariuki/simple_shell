#include "shell.h"

/**
 * _status - function to check availability of the path
 * @cmd: command 
 * Return: 0 or -1 
 */
int _status(char *cmd)
{
	struct stat str;

	if (stat(cmd, &str) == 0)
		return (0);
	else
		return (-1);
}
