// MEMORY MANAGEMENT – FIRST FIT -22C075
#include<stdio.h>
int mem[4]={100,300,500,700};
int i,j;
void first(int req[3],int n_p,int n_b)
{
   int alloc[3],occupy[4];
   for(i=0;i<n_b;i++)
	  occupy[i]=0;
   for(i=0;i<n_p;i++)
	  alloc[i]=-1;
   for(i=0;i<n_p;i++)
   {
	for(j=0;j<n_b;j++)
	{
	  if(!occupy[j] && mem[j] >= req[i])
	  {
		   alloc[i]=mem[j];
		   occupy[j]=i;
		   break;
	  }
	}
   }
   printf("\nAllocation is : First Fit ");
	 printf("\nProcess    Required    Allocation      Extra ");
   for(i=0;i<n_p;i++)
   {
	 printf("\nP%d          %d          ",i+1,req[i]);
	 if(alloc[i]!=-1)
	 printf("%d\t       %d",alloc[i],alloc[i]-req[i]);
	 else
	 printf("Not Allocated");
	}
}
void main()
{
  int req[3]={240,500,640},n_p=3,n_b=4;
  printf("\nMemory Blocks :  ");
  for(i=0;i<4;i++)
     printf("%d ",mem[i]);
   first(req,n_p,n_b);
}
