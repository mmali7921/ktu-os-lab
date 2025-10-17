#include <stdio.h>
#include <unistd.h>
int main(){

int i;
pid_t pid;

fork();

pid=getpid();
printf("hello");
printf("id of child process is %d\n",pid);

for(i=0;i<3;i++){
    fork();
    printf("welcome\n");
    }
}