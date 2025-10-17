#include <stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    int rem_bt;
}pro[100];
int n;
int tq;

void input()
{
    for(int i=0;i<n;i++)
    {
        printf("enter the process id\n");
        scanf("%d",&pro[i].pid);
        printf("enter the timequantum id\n");
        scanf("%d",&tq);
        printf("enter the arrival time\n");
        scanf("%d",&pro[i].at);
        printf("enter the burst time\n");
        scanf("%d",&pro[i].bt);  
        pro[i].rem_bt=pro[i].bt;
        pro[i].ct=0;
        pro[i].wt=0;
        pro[i].tat=0;
    }
}


void showProcess(){
    printf("\npid\tbt\tat\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\n",pro[i].pid,pro[i].at,pro[i].bt);

    }
}
void calCT(){
  int done=0,time=0;
    while(done<n){
        for(int i=0;i<n;i++){
            if(pro[i].rem_bt>0 && pro[i].at<=time){
                if(pro.[i].rem_bt>tq){
                    time+=tq;
                    pro[i].rem_bt-=tq;
                }
                else{
                    time+=pro[i].rem_bt;
                    pro[i].ct=time;
                    pro[i].rem_bt=0;
                    done++;
                }

        }
}
}
}
void calTAT(){
    for ( int i = 0; i < n; i++)
    {
        pro[i].tat=pro[i].ct-pro[i].at;
    }
    
}
void calWT(){
    for ( int i = 0; i < n; i++)
    {
        pro[i].wt=pro[i].tat-pro[i].bt;
    }
    
}
void calAvg(){
    float avgtat,avgwt;
    for ( int i = 0; i < n; i++)
    {
       avgtat+=pro[i].tat;
       avgwt+=pro[i].wt;
    }
    printf("avgwt=%f/n avgtat=%f",avgwt/n,avgtat/n);
}
int main(){
    printf("enter the number of processes\n");
    scanf("%d",&n);

    input();
    showProcess();
    calCT();
    calTAT();
    calWT();
    calAvg();

    return 0;
}