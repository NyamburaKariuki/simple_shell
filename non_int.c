#include "shell.h"

/**
 * non_int - Executes programw in non interactive shell mode
 * @va: Parameters used in the program
 * @ev: variables in the environment
 * @view: ineteraction mode (1)
 *
 * Return: void
 */
void non_int(char **va, char **ev, int view)
{
	char buff[256];
	int size;

	while (fgets(buff, 255, stdin) != NULL)
	{
		size = (int) strlen(buff);
		if (buff[0] == '\n')
			continue;
		if (buff[size - 1] == '\n')
			buff[size - 1] = '\0';
		chain_command(buff, va, ev, view);
	}
}
