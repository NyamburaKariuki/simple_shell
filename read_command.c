#include "shell.h"
/**
 * read_command_display - reads the display command
 * @status: points to the display command
 * @position: position
 * Return: returns status
 */
char *read_command_display(char *status, size_t position)
{
	if (fgets(status, position, stdin) == NULL)
	{
		if (feof(stdin))
		{
			s_error("File Ends");
			exit(0);
		}
		else
		{
			s_error("Reading input Error\n");
			exit(1);
		}
	}
	status[strcspn(status, "\n")] = '\0';
	return (status);
}
