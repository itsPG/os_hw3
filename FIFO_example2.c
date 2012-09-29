#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	This example shows how to (c)reate/(w)rite/(r)ead from a FIFO.
*/
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage : %s [-c/-w/-r] FIFO_name\n", argv[0]);
		exit(0);
	}
	if (strcmp(argv[1],"-c") == 0)
	{
		if (mkfifo(argv[2], 0666) < 0)
		{
			perror("mkfifo failed");
		}
		else
		{
			printf("mkfifo successed.\n");
			exit(0);
		}
	}
	else if (strcmp(argv[1],"-r") == 0)
	{
		int fd;
		fd = open(argv[2], O_RDONLY);
		char buf[1001];
		int len;
		while (len = read(fd, buf, sizeof(buf)))
		{
			if (len == -1)
			{
				exit(0);
			}
			else
			{
				printf("Read %d byte(s) : %s", len, buf);
				memset(buf, 0, sizeof(buf));
			}

		}
	}
	else if (strcmp(argv[1],"-w") == 0)
	{
		int fd;
		fd = open(argv[2], O_WRONLY);
		char buf[1001];
		while (1)
		{
			memset(buf, 0, sizeof(buf));
			fgets(buf, sizeof(buf), stdin);
			write(fd, buf, strlen(buf));
		}
	}
	
	return 0;

}
