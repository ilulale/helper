#include<stdio.h>

struct sjf
{
    int id,at,bt;
};

int main(){
    int i,j,n;
    printf("Enter number of jobs\n");
    scanf("%d",&n);
    struct sjf task[5],wait[5];
    /*wait and task taken as static due to pc giving adress for some reason */
    for ( i = 0; i < n; i++)
    {
        printf("Enter job arrival\n");
        scanf("%d",&task[i].at);
        printf("Enter burst time\n");
        scanf("%d",&task[i].bt);
        task[i].id=i+1;
    }
    /*for ( i = 0; i < n; i++)
    {
        printf("ID:%d AT:%d BT:%d\n",task[i].id,task[i].at,task[i].bt);                                                            
    }*/

    /*Assuming the entries are within 5 and sorted according to arrival time */
    
    int time=0;
    for ( i = 0; i <=n; i++)
    {
        if (task[i+1].bt<task[i].bt && time>=task[i+1].at)
        {
            wait[0].id=task[i+1].id;
            wait[0].bt=task[i+1].bt;
            wait[0].at=task[i+1].at;
            task[i+1].id=task[i].id;
            task[i+1].at=task[i].at;
            task[i+1].bt=task[i].bt;
            task[i].id=wait[0].id;
            task[i].bt=wait[0].bt;
            task[i].at=wait[0].at;
            i=0;
            
        }else
        {
            time+=task[i].bt;
        }
        
        
    }
    time=0;
    for ( i = 0; i <=n; i++)
    {
      time+=task[i].bt;  
    }
    
    for ( i = 0; i < n; i++)
    {
        printf("ID:%d AT:%d BT:%d\n",task[i].id,task[i].at,task[i].bt);                                                         
    }
    printf("Time:%d",time);

/*program gives gnatt chart and proper total time */    
}
