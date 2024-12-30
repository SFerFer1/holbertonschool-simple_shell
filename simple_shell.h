#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
char *find_exec(const char *filename);
char *my_getenv(const char *name);
void free_split_string(char **words);
int count_strings(char *str);
char *_strdup(char *str);
char  **split_string(char *str);
#endif
