// Circular queue

#include<stdio.h>


#define MAX 6

int queue[MAX],front=-1,rear=-1;

int isEmpty()
{
   return(rear==-1 && front==-1);
}

int isFull()
{
   return((rear+1)%MAX==front);
}


void enQueue(int x)
{
   if(isFull())
            printf("\nOverflow");
   else if(isEmpty())
   {
        front=rear=0;
       queue[rear]=x;
   }
  else
  {
        rear=(rear+1)%MAX;
        queue[rear]=x;
  }
}

void deQueue()
{
   if(isEmpty())
      printf("\nUnderFlow");
   else if(front==rear)
    {
       printf("\nRemoved : %d",queue[front]);
       front=rear=-1;
     }   
else
   {
      printf("\nRemoved : %d",queue[front]);
      front=(front+1)%MAX;
  }
}


void dis()
{
    int i=front;
    printf("\nQueue is : ");
    while(i!=(rear+1)%MAX)
     {
         printf("%d ",queue[i]);
         i=(i+1)%MAX;
     }
}


void main()
{
    int i;
   // for(i=0;i<10;i++)
    // {
   //       if(i%2==0)
  //            enQueue(i);
  //     }
   enQueue(10);
   enQueue(20);
   enQueue(30);
     dis();
     deQueue();
      dis();
}