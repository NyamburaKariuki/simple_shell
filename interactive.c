#include "shell.h"

/**
 * _int - Execute in shell interactive mode
 * @ar: parameters of the program
 * @ev: viariables in an environment
 * @view: interaction mode (1)
 * Return: void
 */
void _int(char **ar, char **ev, int view)
{
	char *s;
	int size;

	s = run_prompt();
	while (strlen(s) == 1 && s[0] == '\n')
	{
		char *tmp = s;

		free(tmp);
		s = run_prompt();
	}

	size = (int) strlen(s);
	s[size - 1] = '\0';
	if (s[0] == '#')
		free(s);
	else if (hash_tag(s))
	{
		char **hash = _parse(s, "#");

		free(s);
		chain_command(hash[0], ar, ev, view);
		free_arr(hash);
	}
	else
		chain_command(s, ar, ev, view);
}
