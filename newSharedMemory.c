#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SEGSIZE 100

void main()
{
    int shmid , key =ftok(".", 's'); 
    char *segptr, buff[] = "Hello";
    
    shmid = shmget(key, SEGSIZE, IPC_CREAT | 0666);
    
    printf("Creating or accessing a shared memory segment\n");
    printf("SHMID: %d\n", shmid);
    
    system("ipcs -m");
    
    segptr = (char*)shmat(shmid, 0, 0);
    
    printf("Writing data to shared memory...\n");
    strcpy(segptr, buff);
    printf("DONE\n");
    
    printf("Reading data from shared memory...\n");
    printf("DATA: %s\n", segptr);
    printf("DONE\n");
    
    printf("Detaching...\n");
    shmdt(segptr);
    printf("DONE\n");
    
    printf("Removing shared memory segment...\n");
    shmctl(shmid, IPC_RMID, 0);
    printf("Removed Successfully\n");
    
}
