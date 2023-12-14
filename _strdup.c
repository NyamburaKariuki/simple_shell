#include "shell.h"
/**
  *_strdup - function to duplicate a string
  *@s: string
  *Return: Always 0 (Success)
  */

char *_strdup(char *s)
{
	char *string;
	size_t length, x;

	length  = strlen(s);
	string = malloc(sizeof(char) * (length + 1));
	if  (!string)
	{
	return (NULL);
	}
	for (x = 0; x <= length; x++)
	{
	string[x] = s[x];
	}
	return (string);
}

