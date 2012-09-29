#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

/*
	This example shows how to use shared memory with a selected key.
*/

int main()
{
	/*****************      Part 1      *****************/
	/* create a shared memory. key:9527, size:1024      */

	int shm_id = shmget(9527, 1024, IPC_CREAT|0666);
	/* use IPC_CREAT to create a new shared memory*/
	
	if (shm_id < 0)
	{
		perror("shmget");
		exit(1);
	}
	printf("shm_id is %d\n", shm_id);
	system("ipcs -m"); /* show shared memory list by ipcs command.*/


	/*****************      Part 2      *****************/
	/* attach to shared memory, write msg, and detach.  */

	shm_id = shmget(9527, 1024, 0666);
	char *buf = (char *)shmat(shm_id, 0, 0);
	if (buf < (char*)0)
	{
		perror("shmat");
		exit(1);
	}

	strcpy(buf, "sharememory copy test\n");

	shmdt(buf);

	/*****************      Part 3      *****************/
	/* attach to shared memory, read msg, and detach.  */

	buf = (char *)shmat(shm_id, 0, 0);
	if (buf < (char*)0)
	{
		perror("shmat");
		exit(1);
	}


	printf("Got : %s\n", buf);

	shmdt(buf);

	return 0;
}