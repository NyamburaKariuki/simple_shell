#include "shell.h"
/**
  *_strspn - fucntion that gets a substring from a string
  *@str: string
  *@acc: bytes
  *Return: Always 0 (Success)
  */
unsigned int _strspn(char *str, char *acc)
{
	unsigned int y = 0;
	int p;

	while (*str)
	{
		for (p = 0; acc[p]; p++)
		{
			if (*str == acc[p])
			{
				y++;
				break;
			}
			else if (acc[p + 1] == '\0')
				return (y);
		}
		str++;
		}
		return (y);
}
