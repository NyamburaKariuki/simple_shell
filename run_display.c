#include "shell.h"

/**
 * run_command - combine the commands
 * @s: String
 * @va: parameters
 * @ev: variables
 * @status: 1 or 0
 *
 * Return: 0 or -1
 */
int run_command(char *s, char **va, char **ev, int status)
{
	char **argv, *view, *path;
	int f, res;

	argv = _parse(s, " ");
	if (status == 1)
		free(s);
	if (!argv[0])
	{
		free(argv);
		return (0);
	}
	else if (check_built(argv[0]))
	{
		res = builtin_exec(argv, va, ev);
		return (res);
	}
	else
	{
		f = _status(argv[0]);
		if (f == 0)
		{
			if (access(argv[0], X_OK) == 0)
				res =  (execute_cmd(argv[0], argv, ev));
			else
			{
				write(2, va[0], strlen(va[0]));
				write(2, ": 1: ", 5);
				write(2, argv[0], strlen(argv[0]));
				write(2, ": Permission denied\n", 20);
				res = -1;
			}
		}
		else
		{
			path = get_ev("PATH", ev);
			view = exec_path(path, argv[0]);
			if (!view)
			{
				write(2, va[0], strlen(va[0]));
				write(2, ": 1: ", 5);
				write(2, argv[0], strlen(argv[0]));
				write(2, ": not found\n", 12);
				res = -1;
			}
			else
			{
				res = (execute_cmd(view, argv, ev));
				free(view);
			}
		}
	}
	free_str(argv);
	return (res);
}

/**
 * chain_command - checks for chained command
 * @s: the command checked
 * @va: parameters
 * @ev: variables
 * @status: int or non -int
 *
 * Return: void
 */
void chain_command(char *s, char **va, char **ev, int status)
{
	int x;

	if (s_c_check(s))
	{
		char **array = _parse(s, ";");

		if (status)
			free(s);
		x = 0;
		while (array[x])
		{
			if (strcmp(array[x], "exit") == 0)
			{
				while (array[x])
				{
					free(array[x]);
					x++;
				}
				free(array);
				exit(0);
			}
			run_command(array[x], va, ev, status);
			x++;
		}
		free(array);
	}
	else
		run_command(s, va, ev, status);
}
