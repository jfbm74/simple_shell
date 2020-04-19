#ifndef HOLBERTON_H
#define HOLBERTON_H

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdarg.h>

extern char **environ;

/**
* struct builtin - struct that contains the builtin commands
* @b_name: name of the command
* @b_func: pointer to a function
*/
typedef struct builtin
{
	char *b_name;
	int (*b_func)();
} builtin_struct;

/*Global variables*/
int loop;
char *hsh_home;
int errcode;
char *ptr_dup;

/*Builtin functions*/
int (*find_builtins(char *user_input))();
int exit_func(void);
int env_func(void);

void change_equal_sig(char *str);
char *ret_path_line();
void error_msg(char **args);
char **get_path(char *args);
char *_insert_path(char **args, char **path);
char **getenvpath(void);
void freedom(int n, ...);
int non_interactive_mode(char **av);
int _interactive(char **av __attribute__((unused)));
int necklace_pearls(char *buffer);
char **parsing(char *buffer, int characters);
int execo(char *command, char **args);
void free_all(char **dptr1, char **dptr2, char *sptr1, char *sptr2);
void logo();
/*Utilities*/
int strncomparer(char *s1, char *s2, size_t n);
int strlarge(char *s);
char *strduplicate(char *s);
int strcomparer(char *s1, char *s2);
char *strconk(char *dest, char *src);
int spaces_buster(char *buffer);

int lennum(int n);
char *int_to_charac(int num);

char *_strcat(char *dest, char *src);
char *_strdup(char *s);
char *_itoa(int num);
char *_strstr(char *x, char *y);
int _compare(char *x, char *y);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);

#endif
