#include <stdio.h>

int main(){
    int np,nf,page[50],frame[10],j=0,page_fault=0,i;

    printf("Enter the total number of pages : ");
    scanf("%d",&np);
    printf("Enter the pages : \n");
    for(int i=1;i<=np;i++){
        printf("Page%d: ",i);
        scanf("%d",&page[i]);
    }
    printf("Enter the number of frames : ");
    scanf("%d",&nf);
    for(int i=0;i<nf;i++){
        frame[i] = -1;
    }

    for(i=1;i<=np;i++){
        printf("%d\t",page[i]);
        int avail = 0;
        for(int k=0;k<nf;k++){
            if(frame[k] == page[i]){
                avail = 1;
                break;
            }
        }
        if(avail == 0){
                frame[j] = page[i];
                j = (j+1)%nf;
                page_fault++;
                for(int k=0;k<nf;k++){
                    printf("%d\t",frame[k]);
                }
            }
            printf("\n");
        }

    

    printf("Number of page faults : %d \n",page_fault);
    return 0;
}