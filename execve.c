#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main (void)
{
	char *argv[] = {"ls", "-l", "/tmp", NULL};
	char *envp[] = {NULL};
	pid_t h1, h2, h3, h4, h5;

	h1 = fork();
	if (h1 > 0)
	{
		waitpid(h1, NULL, 0);
		
		h2 = fork();
		if ( h2 > 0)
		{
			waitpid(h2, NULL, 0);

			h3 = fork();
			if ( h3 > 0)
			{	
				waitpid(h3, NULL, 0);

				h4 = fork();
				if (h4 > 0)
				{
					waitpid(h4, NULL, 0);

					h5 = fork();

					if (h5 == 0)
						waitpid(h5, NULL, 0);
				}
			}
		}
	}
	if (h1 == 0 || h2 == 0 || h3 == 0 || h4 == 0 || h5 == 0)
	{
	execve("/bin/ls", argv, envp);
	perror("Execve falló");
	return (1);
	}
return (0);
}
