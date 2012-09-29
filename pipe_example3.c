#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 256
/* 
	This example shows that how to execute another program in child process.
	And how to redirect stdout to pipe, so we can read the others program's stdout.
*/
int main()
{
	int fd[2];
	char read_buf[BUF_SIZE];
	int read_size;
	if (pipe(fd) < 0)
	{
		perror("Pipe failed: ");
		exit(1);
	}

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
	}
	else
	{
		close(fd[0]); /* Close unused read pipe. */
		close(1);  /* Close stdout . */
		dup(fd[1]); /* Copy fd[1] to the first empty fd (stdout) */
		close(fd[1]); /* Remember to close fd[1] after we dup() it.*/
		char *arg_list[] =
		{
			"ls", "-la", NULL
		};

		execvp("ls", arg_list);
	}

	return 0;

}