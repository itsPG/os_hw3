#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/*
	In this example, stdout will be redirected to test.txt.
*/
int main()
{
	int fd;
	char buf[1024];
	int read_size;

	fd = open("test.txt", O_WRONLY);
	if (fd == -1)
	{
		perror("Open failed\n");
		exit(1);
	}
	close(1); /* close stdout */
	dup(fd); /* dup fd to the first empty place of FD's table. */


	printf("This is a dup test\n");
	printf("stdout will be redirected to test.txt.\n");
	return 0;


}
