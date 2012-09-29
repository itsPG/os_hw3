#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 1024
/*
	In this example, "test.txt" is opend and will be read BUF_SIZE bytes until reach the EOF.
*/
int main()
{
	int fd;
	char buf[1024];
	int read_size;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Open failed\n");
		exit(1);
	}

	printf("FD is %d\n", fd);

	while (read_size = read(fd, buf, BUF_SIZE))
	{
		printf("Read %d byte(s) from FD %d\n", read_size, fd);
	}

	return 0;


}
