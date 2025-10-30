#include <stdio.h>
#include <stdlib.h>


int main(){
    int Q[100],n,intial,i;
    int ThM=0;
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    printf("Enter the sequence of request:\n");
    for(i=0;i<n;i++){
        scanf("%d",&Q[i]);
    }
    printf("Enter initial head position: ");
    scanf("%d",&intial);
    for(i=0;i<n;i++){
        ThM+=abs(Q[i]-intial);
        intial=Q[i];
    }
    printf("\nTotal Head Movement=%d",ThM);
    printf("\n");

} 