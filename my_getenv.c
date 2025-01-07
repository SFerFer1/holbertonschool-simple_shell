#include "simple_shell.h"
extern char **environ;

/**
 * my_getenv - Busca una variable de entorno y devuelve su valor
 * @name: Nombre de la variable de entorno que se desea buscar
 * Return: Un puntero al string que contiene el valor de la variable
 * de entorno si se encuentra, NULL si la variable no existe
 */

char *my_getenv(const char *name)
{
int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			return (environ[i] + strlen(name) + 1);
		}
	}
	return (NULL);
}
