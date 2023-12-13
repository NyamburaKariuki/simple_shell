#include "shell.h"
/**
  *_strcmp - function to compare 2 strings
  *@str1: first string
  *@str2: second string
  *Return: Always 0 (Success)
  */

int _strcmp(char *str1, char *str2)
{
	int i;

	if (str1 == NULL)
	return (-1);
	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] - str2[i] != 0)
		{
		return (str1[i] - str2[i]);
		}
	}
	return (0);
}
