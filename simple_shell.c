#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
void free_split_string(char **words)
{
	int i;

	if (words == NULL)
		return;

	for (i = 0; words[i] != NULL; i++)
	{
		free(words[i]);
	}

	free(words);
}
int count_strings(char *str)
{
	int count = 0;
	char *temp1 = strdup(str);
	char *token1 = strtok(temp1, " \t");

	while (token1 != NULL)
	{
		count++;
		token1 = strtok(NULL, " \t");
	}
	free(temp1);
	return (count);
}
char  **split_string(char *str)
{
	int cont = 0;
	int num;
	char **words;
	char *temp;
	char *token;

	if (str == NULL || *str == '\0')
		return (NULL);

	num = count_strings(str);
	temp = strdup(str);
	if (num == 0)
	{
		free(temp);
		return (NULL);
	}
	words = (char**) malloc((num + 1) * sizeof(char*));
	if (words == NULL)
	{
		free(temp);
		return (NULL);
	}
	token = strtok(temp, " \t");
	while (token != NULL)
	{
		words[cont] = strdup(token);
		cont++;
		token = strtok(NULL, " \t");
	}
	words[cont] = NULL;
	free(temp);
	return (words);
}

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t recive;
	char **words;
	pid_t pid;

	printf("$ ");
	printf("PATH: %s\n", getenv("PATH"));


	while ((recive = getline(&line, &len, stdin)) != -1) 
	{
		if (line[recive - 1] == '\n') 
			line[recive - 1] = '\0';

		words = split_string(line);

		if (words != NULL && words[0] != NULL) 
		{
			pid = fork();

			if (pid == 0)
			{
				if (execvp(words[0], words) == -1)
				{
					perror("execvp");
					free_split_string(words);
					exit(1);
				}
			} 
			else if (pid > 0)
			{
				wait(NULL);
				free_split_string(words);
			}
			else 
			{
				perror(" it fork wrongg");
				free_split_string(words);
				exit(1);
			}
		}

		printf("$ ");
	}

	free(line);
	return (0);
}
