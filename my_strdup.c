#include "simple_shell.h"

/**
 * _strdup -returns a pointer to a newly allocated space in memory
 *
 *@str: a string
 *
 *  Return:  null f str = NULL
 */

char *_strdup(const char *str)
{
	int len, i;
	char *dup;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;

	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';

	return (dup);
}
