#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main(){

    int smid;

    void *sharedmem;

char buff[100];

    smid=shmget((key_t)1432,1024,0666 | IPC_CREAT);

    printf("id of shared memory is %d\n",smid);

    sharedmem=shmat(smid,NULL,0);
    printf("shared memory attached at %p\n",sharedmem);

    printf("enter the string to be written in shared memory\n");
    fflush(stdout);
    read(0,buff,100);
    strcpy(sharedmem,buff);

    return 0;
}
