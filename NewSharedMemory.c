#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

#define SEGSIZE 100

int main(int argc, char *argv[])
{
    int shmid; 
    key_t key;
    char *segptr;
    char buff[] = "Hello";
    
    key = ftok(".", 's');
    
    if ((shmid = shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        if ((shmid = shmget(key, SEGSIZE, 0)) == -1)
        {
            perror("shmget");
            exit(1);
        }
    }
    else
    {
        printf("Creating a new shared memory segment\n");
        printf("SHMID: %d\n", shmid);
    }
    
    system("ipcs –m");
    
    if ((segptr = (char*)shmat(shmid, 0, 0)) == (char*)-1)
    {
        perror("shmat");
        exit(1);
    }
    
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
    
    if (shmctl(shmid, IPC_RMID, 0) == -1)
        printf("Can't Remove Shared memory Segment...\n");
    else
        printf("Removed Successfully\n");
    
    return 0;
}


/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

#define SEGSIZE 100

int main(int argc, char *argv[]) {
    int shmid, key = ftok(".", 's');
    char *segptr, buff[] = "Hello";

    shmid = shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL | 0666);
    if (shmid == -1 && (shmid = shmget(key, SEGSIZE, 0)) == -1) {
        perror("shmget");
        exit(1);
    }

    segptr = (char*)shmat(shmid, 0, 0);
    if (segptr == (char*)-1) {
        perror("shmat");
        exit(1);
    }

    strcpy(segptr, buff);
    printf("Data in shared memory: %s\n", segptr);

    shmdt(segptr);
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}

*/
