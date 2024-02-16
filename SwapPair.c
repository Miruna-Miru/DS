// Swapping as pairs in linked list

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
    ne->next=NULL;
    ne->val=x;
    return ne;
}

void dis(struct node *head)
{
    struct node *tem=head;
    while(tem!=NULL){
           printf("%d->",tem->val);
           tem=tem->next;
 }
 printf("NULL\n");
}
void insert(struct node **head,int x)
{
    struct node *ne=newNode(x),*tem=*head;
    if(*head==NULL)
     {
          *head=ne;
           return;
     }
   while(tem->next!=NULL)
         tem=tem->next;
   tem->next=ne;
}

void swapPair(struct node *head)
{
   struct node *current=head;
    int tem;
    while(current!=NULL && current->next!=NULL)
   {
            tem=current->val;
            current->val=current->next->val;
            current->next->val=tem;
            current=current->next->next;
  }
   printf("\nAfter Swapping : ");
 dis(head);
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
  printf("\nOriginal : ");
  dis(head);
  swapPair(head);
}
            
    