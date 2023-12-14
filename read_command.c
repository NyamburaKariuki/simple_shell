#include "shell.h"

/**
 * execute_file_cmd - function to excute commands of a file
 * @ar: parameters in a program
 * @ev: variables in a given environment
 * @code: interaction mode(0)
 * Return: 0 if a file is present
 */
int execute_file_cmd(char **ar, char **ev, int code)
{
	char buff[1024];
	FILE *fd;
	int size;

	fd = fopen(ar[1], "r");
	if (!fd)
	{
		printf("%s does not exist\n", ar[1]);
		exit(2);
	}
	while (fgets(buff, 255, fd) != NULL)
	{
		size = (int) strlen(buff);
		if (buff[0] == '\n')
			continue;
		if (buff[size - 1] == '\n')
			buff[size - 1] = '\0';
		chain_command(buff, ar, ev, code);
	}
	fclose(fd);
	return (0);
}
