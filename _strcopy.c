#include "shell.h"
/**
  *_strcopy - function to copy a string
  *@src: pointer to source string
  *@dest: pointer destination string
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
