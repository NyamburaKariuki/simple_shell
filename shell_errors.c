#include "shell.h"

void s_error(const char *error)
{
	show_print(error);
	write(STDERR_FILENO, "\n", 1);
}
