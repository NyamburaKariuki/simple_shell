#include "shell.h"
void show_print(const char *context)
{
	write(STDOUT_FILENO, context, strlen(context));
}


