#include <stdio.h>

int findLRU(int time[],int n){
    int i,min=time[0],pos=0;
    for(i=1;i<n;++i){
        if(time[i]<min){
            min=time[i];
            pos=i;
        }
    }
    return pos;
}

int main(){
    int nf,np,frames[10],pages[30],counter=0,time[10],flag1,flag2,faults=0,pos;

    printf("enter no. of pages");
    scanf("%d",&np);
    printf("enter the reference string");
    for(int i=0;i<np;++i){
        scanf("%d",&pages[i]);
    }
    printf("enter no. of frames");
    scanf("%d",&nf);
    for(int i=0;i<nf;++i){
        frames[i]=-1;
    }
    for(int i=0;i<np;++i){
        flag1=flag2=0;
        for(int j=0;j<nf;++j){
            if(frames[j]==pages[i]){
                counter++;
                time[j]=counter;
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0){
            for(int j=0;j<nf;++j){
                if(frames[j]==-1){
                    counter++;
                    faults++;
                    frames[j]=pages[i];
                    time[j]=counter;
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2==0){
            pos=findLRU(time,nf);
            counter++;
            faults++;
            frames[pos]=pages[i];
            time[pos]=counter;
        }
        printf("\n");
        for(int j=0;j<nf;++j){
            printf("%d\t",frames[j]);
        }
    }
    printf("page faults : %d\n",faults);
    return 0;

}