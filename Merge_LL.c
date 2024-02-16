// Merge two sorted linked list

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



void dis(struct node *st)
{
    struct node *tem=st;
    while(tem!=NULL)
   {
           printf("%d->",tem->val);
           tem=tem->next;
   }
           printf("NULL\n");
 }




struct node *merge(struct node *L1,struct node *L2)
{
    struct node result;
    struct node *last=&result;
    while(L1!=NULL && L2!=NULL)
    {
       if(L1->val < L2->val)
       {
          last->next=L1;
           L1=L1->next;
         }
        else
        {
            last->next=L2;
            L2=L2->next;
          }
        last=last->next;
     }
    if(L1!=NULL)
        last->next=L1;
    if(L2!=NULL)
         last->next=L2;
    printf("\nNew list is : ");
   dis(result.next);
   return result.next;
}


void main()
{
    struct node *L1=NULL,*L2=NULL,*ne;
    insert(&L1,2);
     insert(&L1,4);
     insert(&L1,6);
     insert(&L1,8);
       printf("\nLL 1 is  :  ");
     dis(L1);
     insert(&L2,3);
     insert(&L2,5);
     insert(&L2,7);
     insert(&L2,9);
       printf("\nLL 2 is  :  ");
     dis(L2);
    ne= merge(L1,L2);
    printf("\nStarting is : %u",ne);
}

         