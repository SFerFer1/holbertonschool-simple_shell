#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "simple_shell.h"

char *find_exec(const char *filename) {
	char *path_env = getenv("PATH");
	if (path_env == NULL) {
		fprintf(stderr, "No se encontró la variable de entorno PATH\n");
		return NULL;
	}

	char *full_path;

	size_t filename_len = strlen(filename);

	char *path = strtok(path_env, ":");

	while (path != NULL) {
		size_t path_len = strlen(path);


		size_t total_len = path_len + filename_len + 2;


		full_path = malloc(total_len);
		if (full_path == NULL) {
			perror("malloc");
			return NULL;
		}


		snprintf(full_path, total_len, "%s/%s", path, filename);


		struct stat buffer;
		if (stat(full_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR)) {

			return full_path;
		}


		free(full_path);


		path = strtok(NULL, ":");
	}

	return NULL;
}
