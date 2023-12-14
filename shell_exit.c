#include "shell.h"

/**
 * string_exit - Checks for exit
 * @st: string arg
 * @arv: commandline
 *
 * Return: void
 */
void string_exit(char *st, char **arv)
{
	write(1, arv[0], strlen(arv[0]));
	write(1, ": 1", 3);
	write(1, ": exit: Illegal number: ", 24);
	write(1, st, strlen(st));
	print_c('\n');
}
