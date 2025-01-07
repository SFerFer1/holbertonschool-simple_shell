#include "simple_shell.h"

/**
 * Busca un ejecutable en los directorios especificados por PATH
 * Si lo encuentra, devuelve la ruta completa del ejecutable
 * @filename: Puntero a string con el nombre o ruta del archivo ejecutable
 * Return: Retorna un puntero a string con la ruta completa del ejecutable
 * NULL si: El archivo no se encuentra, hay un error de memoria
 * la variable de entorno PATH no está definida
 */

char *find_exec(const char *filename)
{
	char *path_env = my_getenv("PATH"), *full_path, *path_env_copy, *path;
	size_t filename_len;
	struct stat buffer;

	if (filename[0] == '/')
		return (_strdup(filename));
	if (path_env == NULL)
		return (NULL);
	path_env_copy = _strdup(path_env);
	if (path_env_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}
	filename_len = strlen(filename);
	path = strtok(path_env_copy, ":");
	while (path != NULL)
	{
		size_t path_len = strlen(path);
		size_t total_len = path_len + filename_len + 2;

		full_path = malloc(total_len);
		if (full_path == NULL)
		{
			perror("malloc");
			free(path_env_copy);
			return (NULL);
		}
		strncpy(full_path, path, path_len);
		full_path[path_len] = '\0';
		strncat(full_path, "/", total_len - path_len - 1);
		strncat(full_path, filename, total_len - strlen(full_path) - 1);
		if (stat(full_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		{
			free(path_env_copy);
			printf("%s", full_path);
			return (full_path);
		}
		free(full_path);
		path = strtok(NULL, ":");
	}
	free(path_env_copy);
	return (NULL);
}
