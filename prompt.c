#include "shell.h"
/**
 *run_prompt - function to show the prompt of a shell
 *Return: pointer or Null
 */
char *run_prompt(void)
{
	char buffer[512], *s;

	write(1, " shell$ ", 7);

	if (fgets(buffer, 511, stdin) != NULL)
	{
		s = malloc(sizeof(char) * (strlen(buffer) + 1));
		if (!s)
			exit(0);
		strcpy(s, buffer);
		return (s);
	}

	print_c('\n');
	exit(0);
}
