#include "shell.h"
/**
 * get_ev - finds an environment variable
 * @nm: its open keys
 * @_env: environment vars (arrays)
 *
 * Return: v_a or NULL
 */
char *get_ev(char *nm, char **_env)
{
	int x = 0, y = 0, g;
	size_t size = strlen(nm);
	char *kb, *v_a, **array;

	kb = malloc(sizeof(char) * (size + 1));
	if (!kb)
		return (NULL);

	while (_env[x])
	{
		g = (int) size;
		if (strlen(_env[x]) > size && _env[x][g] == 61)
		{
			for (y = 0; y < (int) size; y++)
				kb[y] = _env[x][y];
			kb[y] = '\0';

			if (strcmp(nm, kb) == 0)
			{
				array = _parse(_env[x], "=");
				v_a = malloc(sizeof(char) * (strlen(array[1]) + 1));
				if (!v_a)
					return (NULL);
				strcpy(v_a, array[1]);
				free_str(array);
				free(kb);
				return (v_a);
			}
		}
		x++;
	}
	free(kb);
	return (NULL);
}
