//Queue using LL

#include<stdio.h>
#include<stdlib.h>

struct node 
{
   int val;
   struct node *next;
};

struct node *newNode(int x)
{
   struct node *ne=(struct node *)malloc(sizeof(struct node));
   ne->val=x;
   ne->next=NULL;
   return ne;
}


struct node *enQueue(struct node *rear,int x)
{
    struct node *ne=newNode(x);
    if(rear==NULL)
         return ne;
    rear->next=ne;
    return ne;
}


struct node *deQueue(struct node *front)
{
    struct node *tem=front;
    if(front==NULL)
         return NULL;
    front=front->next;
    free(tem);
   return front;
}


void dis(struct node *st)
{
   struct node *tem=st;
   printf("\nQueue is :  ");
   while(tem!=NULL)
   {
      printf("%d->",tem->val);
      tem=tem->next;
   }
   printf("NULL\n");
}


void main()
{
   struct node *front=NULL,*rear=NULL;
   int Q,i,n,x;
   printf("\nEnter no of queries : ");
   scanf("%d",&Q);
   for(i=0;i<Q;i++)
   {
       scanf("%d",&n);
       if(n==1)
       {
            scanf("%d",& x);
            rear=enQueue(rear,x);
            if(front==NULL)
                front=rear;
        }
       else
           front=deQueue(front);
    }
   dis(front);
}