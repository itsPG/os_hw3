#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	/*
		This wxample shows how can we write something to a FIFO file.
		Before execute this code, you have to open another terminal. And ...
		
		1. Type "mkfifo FIFO_test" to create an FIFO file.
		2. Type "cat < FIFO_test" to listen to this FIFO file.
	*/

	int fd = open("FIFO_test",O_WRONLY);

	int i;
	for (i = 1; i <= 10; i++)
	{
		printf("%d.\n", i);
		write(fd, "FIFO_test\n", 10);
		usleep(500000);
	}
	printf("Ended.\n");

	return 0;
	

}
