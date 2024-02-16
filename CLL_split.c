//Split CLL without count

#include<stdio.h>
#include<stdlib.h>

struct node 
{
   int val;
   struct node *next;
};


struct node *newNode(struct node **head, int x)
{
     struct node *ne=(struct node *)malloc(sizeof(struct node));
    ne->val=x;
    ne->next=*head;
    return ne;
}


void insert(struct node **head,int x)
{
     struct node *ne=newNode(head,x),*last=*head;
     if(*head==NULL){
              *head=ne;
                 ne->next = *head;
}
     else
     {
            while(last->next!=*head)
                     last=last->next;
            last->next=ne;
           ne->next = *head;
       }
}

void dis(struct node *st)
{ 
   struct node *tem=st;
   while(tem->next!=st)
   {
        printf("%d->",tem->val);
         tem=tem->next;
   }
  printf("%d\n",st->val);
}


void split(struct node **head)
{
     struct node *slow=*head,*fast=*head,*half1=*head,*half2,*tem;
     while(fast->next!=*head && fast->next->next!=*head)
     {
           slow=slow->next;
             fast=fast->next->next;
      }
     half2=slow->next; // second half's first i.e) (n/2)+1 th element
    slow->next=*head;
    tem=half2;
    while(tem->next!=*head)
       tem=tem->next;
    tem->next=half2;
   printf("\nHalf1 : ");
   dis(half1);
   printf("\nHalf2 : ");
   dis(half2);
}




void main()
{
   struct node *head=NULL;
   insert(&head,1);
   insert(&head,2);
   insert(&head,3);
   insert(&head,4);
   insert(&head,5);
   insert(&head,6);
  insert(&head,7);
   printf("\nOriginal cll : ");
  dis(head);
  split(&head);
  }
