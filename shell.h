#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <dirent.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>


int run_command(char *s, char **va, char **ev, int status);
void chain_command(char *s, char **va, char **ev, int status);
char *run_prompt(void);
int execute_cmd(char *exe, char **argv, char **ev);
int execute_file_cmd(char **ar, char **ev, int code);
int environment_vars(char **ev);
void string_exit(char *st, char **arv);
int s_c_check(char *st);
int hash_tag(char *st);
int builtin_exec(char **argv, char **ar, char **environ);
int print_c(char c);
char *get_ev(char *nm, char **_env);
char *exec_path(char *dirct, char *ex);
char **_parse(char *s, char *del);
void non_int(char **va, char **ev, int view);
void _int(char **ar, char **ev, int view);
char *display_p(void);
void free_str(char **s);
void free_arr(char **s);
int _status(char *cmd);
int check_built(char *_command);

#endif /*MAIN_H */
