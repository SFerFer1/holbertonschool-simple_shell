#include<stdio.h>
#include<stdlib.h>
#include "simple_shell.h"

int main() 
{
	char *path_env = getenv("PATH");
	char *path_copy = _strdup(path_env);

	char *dir = strtok(path_copy, ":");

	while (dir != NULL) 
	{
		printf("Directorio en PATH: %s\n", dir);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return 0;
}
