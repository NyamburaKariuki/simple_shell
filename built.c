#include "shell.h"
/**
 * check_built - checks if in builtin
 * @_command: command to be used
 * Return: 1 or 0
 */

int check_built(char *_command)
{
	char *built[] = {"exit", "environ", "cd", NULL};
	int x = 0;

	while (built[x])
	{
		if (strcmp(built[x], _command) == 0)
			return (1);
		x++;
	}
	return (0);
}
/**
 * builtin_exec - executes the builtin
 * @argv: argument vector
 * @ar: parameter
 * @environ: variable
 *
 * Return: void
 */
int builtin_exec(char **argv, char **ar, char **environ)
{
	int check;

	if (strcmp(argv[0], "exit") == 0 && argv[1] != NULL)
	{
		int x = 0, ni = 0;

		for (x = 0; argv[1][x]; x++)
		{
			if (x == 0 && argv[1][x] == '-')
				continue;
			if (argv[1][x] < 48 || argv[1][x] > 57)
				ni++;
		}
		if (ni)
		{
			string_exit(argv[1], ar);
			free_str(argv);
		}
		else
		{
			check = atoi(argv[1]);
			free_str(argv);
			exit(check);
		}
	}
	else if (strcmp(argv[0], "exit") == 0)
	{
		free_str(argv);
		exit(0);
	}
	else if (strcmp(argv[0], "environ") == 0 && argv[1] == NULL)
	{
		free_str(argv);
		return (environment_vars(environ));
	}
	return (-1);
}
