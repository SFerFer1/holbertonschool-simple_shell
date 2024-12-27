#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TOKENS 100

char **split_string(const char *str) {
	char *copy;
	char **tokens;
	char *token;
	int i;

	copy = strdup(str);
	tokens = malloc(MAX_TOKENS * sizeof(char *));
	i = 0;

	if (tokens == NULL || copy == NULL) {
		perror("Error al asignar memoria");
		exit(1);
	}

	token = strtok(copy, " ");
	while (token != NULL && i < MAX_TOKENS - 1) {
		tokens[i] = strdup(token);
		i++;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	free(copy);
	return tokens;
}

void free_split_string(char **tokens) {
	int i;

	if (tokens == NULL) return;

	for (i = 0; tokens[i] != NULL; i++) {
		free(tokens[i]);
	}
	free(tokens);
}

void list_path() {
	char *path_env;
	char *path_copy;
	char *dir;

	path_env = getenv("PATH");
	if (path_env == NULL) {
		fprintf(stderr, "Error: No se pudo obtener la variable de entorno PATH.\n");
		return;
	}

	path_copy = strdup(path_env);
	if (path_copy == NULL) {
		perror("Error al duplicar PATH");
		return;
	}

	dir = strtok(path_copy, ":");
	printf("Directorios en PATH:\n");
	while (dir != NULL) {
		printf("  %s\n", dir);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
}

void find_in_path(const char *filename) {
	char *path_env;
	char *path_copy;
	char *dir;
	char full_path[1024];

	path_env = getenv("PATH");
	if (path_env == NULL) {
		fprintf(stderr, "Error: No se pudo obtener la variable de entorno PATH.\n");
		return;
	}

	path_copy = strdup(path_env);
	if (path_copy == NULL) {
		perror("Error al duplicar PATH");
		return;
	}

	dir = strtok(path_copy, ":");

	while (dir != NULL) {
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, filename);
		if (access(full_path, F_OK) == 0) {
			printf("Archivo encontrado: %s\n", full_path);
			free(path_copy);
			return;
		}
		dir = strtok(NULL, ":");
	}

	printf("Archivo no encontrado en PATH.\n");
	free(path_copy);
}

int main(void) {
	char *line;
	char **words;
	size_t len;
	ssize_t recive;
	pid_t pid;

	line = NULL;
	len = 0;

	printf("$ ");
	while ((recive = getline(&line, &len, stdin)) != -1) {
		if (line[recive - 1] == '\n') {
			line[recive - 1] = '\0';
		}

		words = split_string(line);

		if (words != NULL && words[0] != NULL) {
			if (strcmp(words[0], "listpath") == 0) {
				list_path();
			} else if (strcmp(words[0], "find") == 0 && words[1] != NULL) {
				find_in_path(words[1]);
			} else {
				pid = fork();
				if (pid == 0) {
					if (execvp(words[0], words) == -1) {
						perror("execvp");
						free_split_string(words);
						exit(1);
					}
				} else if (pid > 0) {
					wait(NULL);
				} else {
					perror("Error en fork");
				}
			}
		}

		free_split_string(words);
		printf("$ ");
	}

	free(line);
	return 0;
}

