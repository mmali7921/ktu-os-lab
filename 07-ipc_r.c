#include <stdio.h>
#include <sys/shm.h>

int main(){
    int smid;
    void *sharedmem;
    char buff[100];

    smid=shmget((key_t)1432,1024,0666 | IPC_CREAT);
    printf("id of shared memory is %d\n",smid);

    sharedmem=shmat(smid,NULL,0);
    printf("shared memory attached at %p\n",sharedmem);

   printf(" data in shared memory is %s\n",(char*)sharedmem);

    return 0;
}