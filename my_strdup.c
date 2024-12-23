#include "simple_shell.h"
/**
 * _strdup -returns a pointer to a newly allocated space in memory
 *
 *@str: a string
 *
 *  Return:  null f str = NULL
 */
char *_strdup(char *str)
{
char *t;
unsigned int i;
unsigned int largo = 0;

if (str == NULL)
return (NULL);

while (str[largo] != '\0')
largo++;


t = malloc(sizeof(char) * (largo + 1));

if (t == NULL)
return (NULL);


for (i = 0; i < largo; i++)
t[i] = str[i];

t[largo] = '\0';

return (t);
}
