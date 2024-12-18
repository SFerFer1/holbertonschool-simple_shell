#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		words[cont++] = strdup(token);
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
