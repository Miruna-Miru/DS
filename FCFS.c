// FCFS

#include<stdio.h>
#include<conio.h>

void swap(int *x,int *y)
{
   int *tem=x;
   x=y;
   y=tem;
}

void main()
{
   int proc[10],burst[10],wait[10],turn[10],arr[10],t_wait=0,t_turn=0,n,i,j;
   float avg_wait,avg_turn;
  printf("\nEnter total no of process : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
 {
   printf("\nEnter arrivl time, burst time : ");
   scanf("%d %d",&arr[i],&burst[i]);
   proc[i]=i+1;
   wait[i]=0;
 }

for(i=0;i<n;i++)
{
  for(j=i;j<n;j++)
  {
    if(arr[i]>arr[j])
    {
       swap(&arr[i],&arr[j]);
       swap(&burst[i],&burst[j]);
       swap(&proc[i],&proc[j]);
    }
}
}
  turn[0]=burst[0];
  printf("\nProcess         Arrival          Burst               Turn \n");
  printf("\nP#1                  %d                %d                   %d",arr[0],burst[0],turn[0]);
for(i=1;i<n;i++) 
{
   wait[i]=wait[i-1]+burst[i-1];
   turn[i]=wait[i]+burst[i];
   t_wait+=wait[i];
   t_turn+=turn[i]; 
  printf("\nP#%d                %d                  %d                  %d ",proc[i],arr[i],burst[i],turn[i]);
}

avg_wait=t_wait/n;
avg_turn=(t_turn+turn[0])/n;
printf("\nAvg_waiting time : %f , Avg_turn time : %f ",avg_wait,avg_turn);

getch();
}



