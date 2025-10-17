#include <stdio.h>
#include <stdlib.h>


int main(){
    int Q[100],n,intial,i,dir,j,size;
    int ThM=0;
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    printf("Enter the sequence of request:\n");
    for(i=0;i<n;i++){
        scanf("%d",&Q[i]);
    }
    printf("Enter initial head position: ");
    scanf("%d",&intial);
    printf("Enter the disk size (max value): ");
    scanf("%d",&size);

    printf("Enter the direction of the head (0 for left, 1 for right): ");
    scanf("%d",&dir);

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(Q[j]>Q[j+1]){
                int temp=Q[j];
                Q[j]=Q[j+1];
                Q[j+1]=temp;
            }
        }
    }

    printf("SCAN Scheduling:\n");

    if(dir==1){
        for(i=0;i<n;i++){
            if(Q[i]>=intial){
                break;
            }
        }

        for(j=i;j<n;j++){
            ThM+=abs(Q[j]-intial);
            intial=Q[j];
        }
        ThM+=abs(size-1-intial);
        intial=size-1;

        for(j=i-1;j>=0;j--){
            ThM+=abs(Q[j]-intial);
            intial=Q[j];
        }

    }else{
        for(i=n-1;i>=0;i--){
            if(Q[i]<=intial){
                break;
            }
        }

        for(j=i;j>=0;j--){
            ThM+=abs(Q[j]-intial);
            intial=Q[j];
        }
        ThM+=intial;
        intial=0;

        for(i=0;i<n;i++){
            ThM+=abs(Q[i]-intial);
            intial=Q[i];
        }
        
    }

    printf("\nTotal Head Movement=%d",ThM);
    printf("\n");
    return 0;

}