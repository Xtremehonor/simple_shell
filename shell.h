#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


int handle_ctrl_d(char **args);     
int change_directory(char **args);  
int display_help(char **args);   
extern char **environ;
int exit_shell(char **args);   
int string_compare(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);

char *_get_path(char **env);
int parse_path(char **arg, char **env);
char *get_command_line(void);
void print_environment(char **env);
char **tokenize_input(char *lineptr);
void _exit_command(char **args, char *lineptr, int _exit);
int fork_and_execute(char **arg, char **av, char **env,
char *lineptr, int np, int c);


#endif /* SHELL_H */
