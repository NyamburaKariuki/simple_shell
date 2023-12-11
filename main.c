#include "shell.h"

int main(void)
{
        char *status = malloc(120), *str;
        signals();

        while(1)
        {
                show_display();
                str = read_command_display(status, 119);

                if (strcmp(str, "exit") == 0)
                {
                        free(status);
                        exit(0);
                }

                char **args = command_parse(str);
                execute_command(args);

                free(args[0]);
                free(args);
        }
        return (0);
}
