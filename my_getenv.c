#include "simple_shell.h"
extern char **environ;

char *my_getenv(const char *name)
{
int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			return environ[i] + strlen(name) + 1;
		}
	}
	return NULL;
}
