//Two stack using one array

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int array[MAX], top1 = -1, top2 = MAX, i;

void push1(int x)
{
   if (top1 < top2 - 1)
       array[++top1] = x;
   else
       printf("\nSTACK1 overflow");
}

void push2(int x)
{
   if (top1 < top2 - 1)
       array[--top2] = x;
   else
       printf("\nStack2 overflow");
}

void pop1()
{
   if (top1 > -1)
       printf("%d is popped S1\n", array[top1--]);
   else
       printf("\nUnderflow");
}

void pop2()
{
   if (top2 < MAX)
       printf("%d is popped S2\n", array[top2++]);
   else
       printf("\nUnderflow");
}

void dis1()
{
   printf("\nStack 1 is :");
   for (i = top1; i >= 0; i--)
       printf("%d ", array[i]);
   printf("\n");
}

void dis2()
{
   printf("\nStack 2 is :");
   for (i = top2; i < MAX; i++)
       printf("%d ", array[i]);
}

int main()
{
    push1(1);
    push1(3);
    push2(2);
    push2(4);
    pop1();
    dis1();
    pop2();
    dis2();

    return 0;
}
