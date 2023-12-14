#include "shell.h"

/**
 * free_str - free allocated space
 * @s: arrays(pointers)
 *
 * Return: void
 */
void free_str(char **s)
{
	int x = 0;

	while (s[x])
	{
		free(s[x]);
		x++;
	}
	free(s);
}

/**
 * free_arr - free allocated space
 * @s: arrays(pointers)
 *
 * Return: void
 */
void free_arr(char **s)
{
	int x = 1;

	while (s[x])
	{
		free(s[x]);
		x++;
	}
	free(s);
}
