#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int exceve (void);
void free_split_string(char **words);
int count_strings(char *str);
char  **split_string(char *str);
char *_strdup(char *str);
#endif
