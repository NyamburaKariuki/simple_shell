#include "shell.h"
/**
 * token_count - counts the args
 * @s: string
 * @del: delimeter
 *
 * Return: number of args
 */
size_t token_count(char *s, char *del)
{
	size_t num = 0;
	int x = 0;

	while (s[x])
	{
		if (x == 0 && s[x] != del[0])
		{
			num++;
			x++;
			continue;
		}
		if (s[x] == del[0] && s[x + 1] != del[0])
		{
			if (s[x + 1] != '\0')
				num++;
		}
		else if ((s[x] == del[0] && s[x + 1] == del[0]))
		{
			x++;
			continue;
		}

		x++;
	}
	return (num);
}
/**
 * _parse - it tokenise the string
 * @s: string
 * @del: delimeter
 *
 * Return: token
 */
char **_parse(char *s, char *del)
{
	char **token;
	int x = 0, begin = 0, y = 0;
	size_t num = token_count(s, del);

	token = malloc(sizeof(char *) * (num + 1));
	while (s[x])
	{
		if (x == 0 && s[x] == del[0])
		{
			s = s + 1;
			x = 0;
			continue;
		}
		if (s[x] == del[0] && x > 0)
		{
			token[y] = malloc(sizeof(char) * (x + 1));
			while (begin < x)
			{
				token[y][begin] = s[begin];
				begin++;
			}
			token[y][begin] = '\0';
			y++;
			begin = 0;
			s = s + x + 1;
			x = 0;
			continue;
		}
		if (s[x] != del[0] && s[x + 1] == '\0')
		{
			token[y] = malloc(sizeof(char) * (x + 2));
			while (begin < x + 1)
			{
				token[y][begin] = s[begin];
				begin++;
			}
			token[y][begin] = '\0', y++;
			break;
		}
		x++;
	}
	token[y] = NULL;
	return (token);
}
