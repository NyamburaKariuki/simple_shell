#include "shell.h"

/**
 * exec_path - Searches PATH directories(ex)
 * @dirct: directories
 * @ex: exec file
 *
 * Return: pointer(string) or NULL
 */
char *exec_path(char *dirct, char *ex)
{
	char *enr, **arr_dir;
	int x = 0;
	DIR *dp;
	size_t len_1, len_2;

	arr_dir = _parse(dirct, ":");
	free(dirct);
	while (arr_dir[x])
	{
		struct dirent *dirct;

		dp = opendir(arr_dir[x]);
		if (!dp)
		{
			closedir(dp);
			free_str(arr_dir);
			return (NULL);
		}
		while ((dirct = readdir(dp)) != NULL)
		{
			if (strcmp(dirct->d_name, ex) == 0)
			{
				len_1 = strlen(arr_dir[x]);
				len_2 = strlen(ex);
				enr = malloc(sizeof(char) * (len_1 + len_2 + 2));
				if (!enr)
					return (NULL);
				strcpy(enr, arr_dir[x]);
				strcat(enr, "/");
				strcat(enr, ex);
				closedir(dp);
				free_str(arr_dir);
				return (enr);
			}
		}
		closedir(dp);
		x++;
	}
	free_str(arr_dir);
	return (NULL);
}
