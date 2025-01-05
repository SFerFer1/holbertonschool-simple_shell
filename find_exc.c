#include "simple_shell.h"

char *find_exec(const char *filename) {
	char *path_env = my_getenv("PATH");
	char *full_path;
	char *path_env_copy;
	size_t filename_len;
	char *path;
	struct stat buffer;
	if (path_env == NULL)
	{
		fprintf(stderr, "No se encontró la variable de entorno PATH\n");
		return NULL;
	}
	
	
	path_env_copy = _strdup(path_env);
    if (path_env_copy == NULL)
    {
        perror("strdup");
        return NULL;
    }


	 filename_len = strlen(filename);
	path = strtok(path_env_copy, ":");

	while (path != NULL) {
		size_t path_len = strlen(path);


		size_t total_len = path_len + filename_len + 2;


		full_path = malloc(total_len);
		if (full_path == NULL) {
			perror("malloc");
			free(path_env_copy);
			return NULL;
		}

		
		strncpy(full_path, path, path_len);
        full_path[path_len] = '\0';

        strncat(full_path, "/", total_len - path_len - 1);

        strncat(full_path, filename, total_len - strlen(full_path) - 1);


		
		if (stat(full_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR)) {
			free(path_env_copy);
			return full_path;
		}


		free(full_path);


		path = strtok(NULL, ":");
	}
	free(path_env_copy);
	return NULL;
}
