#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* 
	This example demostrate the basic usage of signal, raise, and kill.
*/

void handler(int sig_no)
{
	printf("handler is called.\n");
	printf("Catch %d\n", sig_no);
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

	raise(SIGUSR1);
	raise(SIGUSR2);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR2);

	return 0;
}
