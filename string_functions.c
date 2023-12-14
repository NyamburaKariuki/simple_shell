#include "shell.h"
/**
  *_strcopy - function to to copy a string
  *@src: source string
  *@dest: destination
  *Return: Always 0 (Success)
  */
char *_strcopy(char *src, char *dest)
{
	int x = 0;

	while (src[x])
	{
	dest[x] = src[x];
	x++;
	}
	dest[x] = '\0';
	return (dest);
}
/**
  *_catoi - function to convert a string to an integer
  *@str: string to conevrt
  *Return: Always 0 (Success)
  */
int _catoi(char *str)
{
	int x = 0, y = 1, z;
	unsigned int p = 0;

	while (str[x] != '\0')
	{
		if (str[x] == '-')
		{
			return (2);
		}
		z = str[x] - '0';

		if (p > 0 && !(z >= 0 && z <= 9))
			break;

		if (z >= 0 && z <= 9)
			p = p * 10 + z;

		x++;
	}
	p *= y;
	return (p);
}
/**
 *schar - function that checks a character in a string
 * @str: string to check
 * @chr: character to check
 * Return: pointer to char
 */
char *schar(char *str, char chr)
{
	do {
		if (*str == chr)
		{
			break;
		}
	} while (*str++);
	return (str);
}
