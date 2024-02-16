//Reverse SLL without using stack

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


void insert(struct node **head,int x)
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

void dis(struct node *no)
{
     while(no!=NULL)
     {
          printf("%d->",no->val);
          no=no->next;
      }
     printf("NULL\n");
}


void reverse(struct node *head)
{
   struct node *pre=NULL,*current=head,*nex;
   printf("\nOriginal is : ");
   dis(head);
   while(current!=NULL)
   {
           nex=current->next;
           current->next=pre;
            pre=current;
            current=nex;
  }
       printf("\nRreversed is : ");
       dis(pre);
  }




void main()
{
   struct node *head=NULL;
   insert(&head,1);
   insert(&head,2);
  insert(&head,3);
  insert(&head,4);
  reverse(head);
}