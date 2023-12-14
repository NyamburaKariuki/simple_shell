#include "shell.h"
/**
 * s_error - shows the shell errors
 * @error: points to th error
 * Return: nothing
 */
void s_error(const char *error)
{
	fprintf(stderr, "%s\n", error);
}
