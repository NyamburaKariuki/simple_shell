#include "shell.h"
/**
  *_cputs - function to print a string
  *@string: string to print
  *Return: nothing
  */
void _cputs(char *string)
{
	int x;

	for (x = 0; string[x] != '\0'; x++)
	{
		_putchar(string[x]);
	}
	_putchar('\n');
}

/**
*_putchar - Writes the character c to standard output
*@c: the character to print
*Return: 1 on success
*on error, retuns -1 and errno is set appopriately
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
