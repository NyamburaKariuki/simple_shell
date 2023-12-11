#include "shell.h"
void execute_command(char **args)
{
	pid_t pid_child;
	int j;

        if (args[0] != NULL && strcmp(args[0], "exit") == 0)
        {
                for (j = 0; args[j] != NULL; j++)
                {
                        free(args[j]);
                }
                free(args);
                exit(0);
        }

        pid_child = fork();

        if (pid_child == -1)
        {
                s_error("forking error");
                exit(1);
        }
        else if (pid_child == 0)
        {
                execvp(args[0], args);
                show_print("No such file or directory.\n");
                exit(1);
        }
        else
        {
                wait(NULL);
        }
}
