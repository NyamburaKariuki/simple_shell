#include "shell.h"
/**
  *s_c_check - function to check if cmd has ;
  *@st: string(command)
  *Return: 0 or 1
  */
int s_c_check(char *st)
{
	int x = 0;

	while (st[x])
	{
		if (st[x] == ';')
			return (1);
		x++;
	}
	return (0);
}
/**
  *hash_tag - function to check for # in command
  *@st: string(command)
  *Return: 0 or 1
  */
int hash_tag(char *st)
{
	int x = 0;

	while (st[x])
	{
		if (st[x] == '#')
			return (1);
		x++;
	}
	return (0);
}
