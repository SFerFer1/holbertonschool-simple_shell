#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count_strings(char *str)
{
	int count = 0;
	char *temp1 = strdup(str);
	char *token1 = strtok(temp1, " \t");

	if (token1 != NULL)
	{
		count++;
		token1 = strtok(NULL, " \t");
	}
	free(temp1);
	return (count);
}
char  **split_string(char *str)
{
	int num = count_strings(str);
	char **words = (char**) malloc(num * sizeof(char*));
	char *temp = strdup(str);
	int cont = 0;
	char *token = strtok(temp, " \t");
	if (token != NULL)
	{
		words[cont++] = token;
		token = strtok(NULL, " \t");
	}
	free(temp);
	return (words);
}

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t recive;

	if (line == NULL)
		printf("$ ");

	while ((recive = getline(&line, &len, stdin)) != -1)
	{
		dividir(line);
		printf("%s$ ", line);
	}

	free(line);
	return(0);
}
