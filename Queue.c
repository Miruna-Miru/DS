//Queue

#include<stdio.h>

#define MAX 10

int front=-1,rear=-1,queue[MAX],i;

int isEmpty()
{
      return(front==-1||front>rear);
}

int isFull()
{
    return(rear==MAX-1);
}


void display()
{
    printf("\nQueue is : ");
    for(i=front;i<=rear;i++)
          printf("%d  ",queue[i]);
}


void enQueue()
{
    int x;
    if(!isFull())
    {
        printf("\nEneter element : ");
        scanf("%d",&x);
        rear++;
        queue[rear]=x;
        if (front == -1) {
            front = 0;  
        }
        printf("\nElement added");
     }
     else
        printf("\nQueue is full");
}


void deQueue()
{
      if(!isEmpty())
      {
           printf("\nElement %d is removed",queue[front]);
           front++;
       }
      else
          printf("\nQueue is empty");
}


void main()
{
     int ch=0;
     printf("1-enQueue\t2-deQueue\t3-Display\t4-Exit");
     while(ch!=4)
     {
         printf("\nEnter choice : ");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1 :
                        enQueue();
                        break;
             case 2 :
                        deQueue();
                        break;
             case 3 :
                        display();
                        break;
             case 4  :
                        printf("\nExiting..............");
                        break;
           }
        }
 }
    