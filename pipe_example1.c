#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 256
/*
This example shows the basic usage of pipe.
*/
int main()
{
	int fd[2];
	char buf[BUF_SIZE], read_buf[BUF_SIZE];
	int read_size;
	memset(buf, 0, sizeof(buf));
	memset(read_buf, 0, sizeof(read_buf));
	strcpy(buf, "Hello World!\n");


	if (pipe(fd) < 0) /* pipe(fd) will create pipe and set fd number to fd[0] and fd[1].*/
	{
		perror("Pipe failed: ");
		exit(1);
	}
	
	write(fd[1], buf, strlen(buf));
	read_size = read(fd[0], read_buf, BUF_SIZE);
	printf("Read %d byte(s) from fd[0]\n", read_size);
	printf("Got : %s", read_buf);


	return 0;

}