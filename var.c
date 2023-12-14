#include "shell.h"
/**
 * environment_vars - show all environment variables
 * @ev: environment variabless
 * Return: 0 Success
 */
int environment_vars(char **ev)
{
	int x = 0;

	while (ev[x])
	{
		write(1, ev[x], strlen(ev[x]));
		print_c('\n');
		x++;
	}
	return (0);
}
