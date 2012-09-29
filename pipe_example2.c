#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 256
/* 
	In this example, child will write message to parent.
	To do this, we need to create a new pipe before we fork this process.
	After we forked, parent need to close fd[1] and child need to close fd[0].
*/
int main()
{
	int fd[2];
	char* msg[] = {"this\n", "is\n", "a\n", "pipe-message\n", "test.\n"};
	char buf[BUF_SIZE], read_buf[BUF_SIZE];
	int read_size;
	if (pipe(fd) < 0)
	{
		perror("Pipe failed: ");
		exit(1);
	}
	memset(buf, 0, sizeof(buf));
	strcpy(buf, "Hello World!\n");

	pid_t pid;
	if (pid = fork())
	{
		if (pid < 0)
		{
			perror("Fork() failed: ");
			exit(1);
		}
		close(fd[1]); /* Close unused write pipe. */
		int read_size, count = 0;

		while (read_size = read(fd[0], read_buf, BUF_SIZE))
		{
			count++;
			printf("Read %d byte(s) from fd[0]\n", read_size);
			printf("Got : %s", read_buf);
			memset(read_buf, 0, sizeof(read_buf));
		}
		printf("Read failed from fd[1] (probably pipe is closed.), exit.\n");
		exit(0);
	}
	else
	{
		close(fd[0]); /* Close unused read pipe. */

		int i;
		for (i = 0; i < 5; i++)
		{
			
			write(fd[1], msg[i], strlen(msg[i]));
			usleep(500000); /* sleep for 0.5sec */
		}
		exit(0);
	}

	return 0;

}