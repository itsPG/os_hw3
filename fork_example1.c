#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
	This is the basic fork function.

*/
int main()
{
	pid_t pid;
	pid = fork();
	if (pid < 0)
	{
		printf("Fork() failed\n");
		exit(1);
	}
	else if (pid == 0) /* child process */
	{
		printf("This is child process. PID: %u\n", getpid());
	}
	else /* parent process */
	{
		printf("This is parent process. PID: %u\n", getpid());
		printf("child is %u\n", getpid());
	}
	return 0;
}