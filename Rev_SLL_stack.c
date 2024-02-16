//Reverse SLL using stack

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct node
{
  int val;
  struct node *next;
};
 

int i,stack[MAX],top=-1;
 
int isEmpty()
{
   return (top==-1);
}

int isFull()
{
    return(top==MAX-1);
}


void push(int x)
{
   if(!isFull()){
   top++;
   stack[top]=x;
  }
  else
     printf("\nFull");
}

int pop()
{
   int c;
  if(!isEmpty())
  {
     c=stack[top];
     top--;
   }
   return c;
 }


struct node *newNode(int x)
{
     struct node *ne=(struct node*)malloc(sizeof(struct node));
    ne->val=x;
    ne->next=NULL;
    return ne;
}


void insert(struct node **head, int x)
{
  struct node *ne=newNode(x),*tem=*head;
  if(*head==NULL)
     *head=ne;
 else
{
   while(tem->next!=NULL)
       tem=tem->next;
   tem->next=ne;
}
}

int disSLL(struct node *head)
{
    int c=0;
    struct node *tem=head;
    printf("\nOriginal :  ");
     while(tem!=NULL)
     {
        printf("%d->",tem->val);
        tem=tem->next;
        c++;
       }
    printf("NULL\n");
    return c;
}


void popSLL(struct node **head)
{
     struct node *tem=*head;
     if(*head=NULL)
     {
      printf("\nEpyty");
     return;
    }
   *head=tem->next;
    push(tem->val);
    free(tem);
      
}

void main()
{
   int i,n;
   struct node *head=NULL;
    insert(&head,1);
   insert(&head,2);
     insert(&head,3);
      insert(&head,4);
    n=disSLL(head); 
   printf("\nReversed is : ");
    for(i=0;i<n;i++)
       popSLL(&head);
for(i=0;i<n;i++)
     printf("%d->",pop());
    printf("NULL\n");
}
  
    
