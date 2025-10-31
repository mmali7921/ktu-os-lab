#include <stdio.h>
struct process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int pr;
}pro[100];
int n;
void input(){
    for(int i=0;i<n;i++){
    printf("Enter the pid ");       
    scanf("%d",&pro[i].pid);
    printf("Enter the arrival time ");
    scanf("%d",&pro[i].at);
    printf("Enter the burst time ");
    scanf("%d",&pro[i].bt);
    printf("Enter the priority ");
    scanf("%d",&pro[i].pr);
    }
}
void sort(){
    struct process temp;
    for(int i=0;i<n-1;i++){         
        for(int j=0;j<n-i-1;j++){
            if(pro[j].at > pro[j+1].at){        
                temp=pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=temp;
            }
        }
    }
}
void showProcess(){
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tPR\n");               
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pro[i].pid,pro[i].at,pro[i].bt,pro[i].ct,pro[i].tat,pro[i].wt,pro[i].pr);
    }
}
void calCT(){
    int time=0;
    int completed=0;
    int done[100]={0};
    while(completed!=n){
        int highestPr=9999;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(pro[i].at<=time && done[i]==0){
                if(pro[i].pr<highestPr){
                    highestPr=pro[i].pr;
                    idx=i;
                }
                else if(pro[i].pr==highestPr && idx!=-1 && pro[i].at<pro[idx].at){
                    idx=i;
                }
            }
        }
        if(idx==-1){
            time++;
        }
        else{
            pro[idx].ct=time + pro[idx].bt;
            time=pro[idx].ct;
            done[idx]=1;
            completed++;
        }
    }
}
void calTAT(){
    for(int i=0;i<n;i++){
        pro[i].tat=pro[i].ct - pro[i].at;
    }
}
void calWT(){
    for(int i=0;i<n;i++){       
        pro[i].wt=pro[i].tat - pro[i].bt;
    }
}   
void calAVG(){
    float totalTAT=0, totalWT=0;
    for(int i=0;i<n;i++){
        totalTAT+=pro[i].tat;
        totalWT+=pro[i].wt;
    }
    printf("Average TAT: %.2f\n", totalTAT/n);
    printf("Average WT: %.2f\n", totalWT/n);
}                        

void main(){
    printf("Enter number of processes ");
    scanf("%d",&n);
    input();
    sort();
    calCT();
    calTAT();
    calWT();
    showProcess();
    
}