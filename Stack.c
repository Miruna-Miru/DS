//Stack

#include<stdio.h>

#define MAX 10
int top = -1,stack[MAX],i;


int isEmpty()
{
     return (top==-1);
}


int isFull()
{
   return(top==MAX-1);
}


void push()
{
   int x;
   if(!isFull())
   {
         printf("\nEnter element to be pushed : ");
         scanf("%d",&x);
        top++;
         stack[top]=x;
         printf("\nElement added");
     }
    else
        printf("\nStack full");
}


void pop()
{
   if(!isEmpty())
   {
       printf("\nElemenet %d is removed",stack[top]);
       top--;
    }
   else
      printf("\nStack is empty");
}


void display()
{
   printf("\nStack is ");
   for(i=top;i>=0;i--)
      printf("\n%d",stack[i]);
}


void main()
{
     int ch=0;
     printf("1-Push\t2-Pop\t3-Display\t4-Exit");
     while(ch!=4)
     {
         printf("\nEnter choice : ");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1 :
                        push();
                        break;
             case 2 :
                        pop();
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