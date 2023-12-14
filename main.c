#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * @ev: variables
 *
 * Return: 0 indicating success
 */
int main(int argc, char **argv, char **ev)
{
	int view = 0;

	if (argc == 2)
	{
		return (execute_file_cmd(argv, ev, view));
	}
	while (isatty(0))
	{
		view = 1;
		_int(argv, ev, view);
	}

	non_int(argv, ev, view);
	return (0);
}
