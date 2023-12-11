#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdout.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

#define TOKEN_DELIM "\t\n\r\a"

void show_display(void);
void show_prompt(void);
void show_print(const char *context);
void s_error(const char *error);
char *read_command_display(char *status, size_t position);
void execute_command(char **args);
char **command_parse(const char *status);
void sig_int(int sign);
void signals(void);

#endif //MAIN_H
