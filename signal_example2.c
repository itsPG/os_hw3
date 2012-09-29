#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
/*
	This example how to use signal to notify another process.

*/
void handler(int sig_no)
{
	printf("Handler is called.\n");
	switch (sig_no)
	{
		case SIGUSR1:
			printf("PID: %d catch SIGUSR1.\n", getpid());
			break;

		case SIGUSR2:
			printf("PID: %d catch SIGUSR2.\n", getpid());
			break;

	}
	return ;

}
int main()
{
	if (signal(SIGUSR1, handler) == SIG_ERR)
	{
		perror("Can't set SIGUSR1: \n");
		exit(1);
	}
	if (signal(SIGUSR2, handler) == SIG_ERR)
	{
		perror("Can't set SIGUSR2: \n");
		exit(1);
	}

	pid_t pid, parent = getpid();
	if (pid = fork())
	{
		if (pid < 0)
		{
			perror("Fork() failed: ");
			exit(1);
		}
		waitpid(-1, 0, 0);
	}
	else
	{
		printf("PID: %d is sending SIGUSR1 to PID %d\n", getpid(), parent);
		kill(parent, SIGUSR1);
		printf("PID: %d is sending SIGUSR2 to PID %d\n", getpid(), parent);
		kill(parent, SIGUSR2);

	}
	return 0;
}
