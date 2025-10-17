#include <stdio.h>
#include <limits.h>
#define max 25

int nb,nf,b[max],f[max],i,j,temp,frag[max],max=INT_MIN;
static int ba[max],fa[max];

int main(){
    printf("enter the number of blocks: ");
    scanf("%d",&nb);
    printf("enter the size of the blocks: ");
    for(i=1;i<=nb;i++){
        printf("Block %d: ",i);
        scanf("%d",&b[i]);
    }
    printf("enter the number of files: ");
    scanf("%d",&nf);
    printf("enter the size of the files: ");
    for(i=1;i<=nf;i++){
        printf("File %d: ",i);
        scanf("%d",&f[i]);
    }
    for(i=1;i<=nf;i++){
        for(j=1;j<=nb;j++){
            if(ba[j]!=1){
                temp=b[j]-f[i];
                if(temp>=0){
                    if(max<temp){
                        max=temp;
                        fa[i]=j;
                    }
                    
                }
            }
        }
        frag[i]=max;
        ba[fa[i]]=1;
        max=INT_MIN;
    }

    printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment");
    for(i=1;i<=nf;i++){
        if(fa[i]!=0)
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],fa[i],b[fa[i]],frag[i]);
        else
            printf("\n%d\t\t%d\t\tNot Allocated",i,f[i]);
    }
    printf("\n");
    return 0;
}