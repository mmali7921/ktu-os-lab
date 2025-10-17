#include <stdio.h>
#include <unistd.h>

int main(){
    printf("heyy/n");
    fflush(stdout);

    char *args[]={"./02-syse2",NULL};
    execv(args[0],args);
    printf("this will not be printed\n");
    return 0;
}