#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>

extern char **environ;
void _sig_handler(int);
char *_getline(void);
int memory_lane(char *buff);
int memory_lane1(char *buff);
char **_str_tok(char *buff, int ptr);
void _exit1(char *buffr, char **cmds);
int _env1(char *buff, char **cmds);
char *_get_env(char *str);
char *_str_cpy(char *des, char *sr);
char *_str_dup(char *str);
char *_str_str(char *rp, char *lp);
int _str_cmp(char *s1, char *s2);
char *_path(char *cmd);
char *_str_cat(char *des, char *sr);
int _str_len(char *s);
char *_find(char **folder, char *cmd);
void _fork(char *buffr, char **cmd, char **argv, int round);
char *_itoa(int number);
int *_p_error(char *argv, char *str, char *cmd);

#endif


