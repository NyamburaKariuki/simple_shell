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
			show_print("File Ends\n ");
			exit(0);
		}
		else
		{
			show_print("Reading input Error\n");
			exit(1);
		}
	}
	/*status[strcspn(status, "\n")] = '\0';*/
	status[_strspn(status, "\n")] = '\0';
	return (status);
}
