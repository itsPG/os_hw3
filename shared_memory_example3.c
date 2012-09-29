#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

/*
	This example shows how to delete a shared memory by shmctl.
*/
int main()
{
	int id;
	system("ipcs -m");
	printf("Input the shared memory id that you want to delete: ");
	scanf("%d", &id);
	if (shmctl(id, IPC_RMID, 0) !=0)
	{
		perror("shmctl IPC_RMID");
	}
	else
	{
		printf("Done\n");
	}
	return 0;


}