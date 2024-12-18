#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char  **dividir(char *str)
{
	const char* separador = " ";
	char *token = strtok(str, separador);
	int cont = 0;
	if (token != NULL)
	{
		cont++;
		printf("%i", cont);
		token = strtok(NULL, separador);

	}
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
