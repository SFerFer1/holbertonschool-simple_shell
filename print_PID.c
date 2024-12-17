#include "main.h"
/**
 *
 *
 *
 *
 */
int print_PID(void)
{
	pid_t myPid;

	myPid = getpid();
	printf("%u\n", myPid);

	return(0);
}
