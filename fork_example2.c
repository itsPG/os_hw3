#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
	This example shows how to let parent wait for child end.
*/
int main()
{
	pid_t pid;
	if (pid = fork())
	{
		if (pid < 0 )
		{
			perror("Fork() failed\n");
		}
		else
		{
			printf("This is parent waiting.\n");
			waitpid(-1, 0, 0);
			printf("Parent end.\n");
		}
	}
	else
	{
		printf("This is child.\n");
		usleep(1000000);
	}
	return 0;
}