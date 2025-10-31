#include <stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
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
    }
}


void showProcess(){
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pro[i].pid,pro[i].at,pro[i].bt,pro[i].ct,pro[i].tat,pro[i].wt);
    }
}
void sort()
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(pro[j].at>pro[j+1].at){
                struct process temp=pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=temp;
            }
        }
    }
}
void calCT() {
    int completed = 0, time = 0, idx;
    int done[100] = {0};

    while (completed != n) {
        int minbt = 9999;
        idx = -1;

        // Find process with minimum burst time among arrived + not done
        for (int i = 0; i < n; i++) {
            if (pro[i].at <= time && done[i] == 0) {
                if (pro[i].bt < minbt) {
                    minbt = pro[i].bt;
                    idx = i;
                }
                // If same burst time, choose earlier arrival
                else if (pro[i].bt == minbt && idx != -1 && pro[i].at < pro[idx].at) {
                    idx = i;
                }
            }
        }

        // If no process has arrived yet
        if (idx == -1) {
            time++;
        } else {
            pro[idx].ct = time + pro[idx].bt;
            time = pro[idx].ct;
            done[idx] = 1;
            completed++;
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
    float avgtat=0,avgwt=0;
    for ( int i = 0; i < n; i++)
    {
       avgtat+=pro[i].tat;
       avgwt+=pro[i].wt;
    }
    printf("avgwt=%f\navgtat=%f",avgwt/n,avgtat/n);
}
int main(){
    printf("enter the number of processes\n");
    scanf("%d",&n);

    input();

    sort();
    calCT();
    calTAT();
    calWT();
    showProcess();
    calAvg();

    return 0;
}