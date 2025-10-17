#include <stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    int prio;
}pro[100];
int n;

void input()
{
    for(int i=0;i<n;i++)
    {
        printf("enter the process id\n");
        scanf("%d",&pro[i].pid);
        printf("enter the arrival time\n");
        scanf("%d",&pro[i].at);
        printf("enter the burst time\n");
        scanf("%d",&pro[i].bt);  
        printf("enter the priority\n");
        scanf("%d",&pro[i].prio);  
    }
}

void sort()
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(pro[j].at>pro[j+1].at || (pro[j].at==pro[j+1].at && pro[j].prio>pro[j+1].prio)){
                struct process temp=pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=temp;
            }
        }
    
    }
}
void showProcess(){
    printf("\npid\tbt\tat\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\n",pro[i].pid,pro[i].at,pro[i].bt);

    }
}
void calCT(){
    int time=0;
    pro[0].ct=pro[0].at+pro[0].bt;
    time=pro[0].ct;

    for(int i=1;i<n;i++){

        if(pro[i].at<time){
            pro[i].ct=time+pro[i].bt;
            time=pro[i].ct;
        }
        else{
            pro[i].ct=pro[i].at+pro[i].bt;
            time=pro[i].ct;
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
    sort();
    showProcess();
    calCT();
    calTAT();
    calWT();
    calAvg();

    return 0;
}