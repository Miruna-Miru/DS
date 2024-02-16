//DLL ShellSort

#include<stdio.h>
#include<stdlib.h>

struct node 
{
   int val;
   struct node *next,*pre;
};

struct node *newNode(int x)
{
    struct node *ne=(struct node *)malloc(sizeof(struct node));
   ne->val=x;
   ne->next=ne->pre=NULL;
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
         ne->pre=tem;
    }
}

struct node *nodeAtIndex(struct node *head,int ind)
{
     int m=0;
     while(m<ind && head!=NULL)
      {
              head=head->next;
              m++;
       }
      return head;
}


void sort(struct node **head)
{
   int i,j,gap,size=0,key;
   struct node *tem=*head;
   if(*head==NULL || (*head)->next==NULL)
              return;
   else
  {
     while(tem!=NULL)
     {
           size++;
           tem=tem->next;
      }
     for(gap=size/2;gap>0;gap/=2)
     {
         for(i=gap;i<size;i++)
         {
                key=nodeAtIndex(*head,i)->val;
                for(j=i;j>=gap && nodeAtIndex(*head,j-gap)->val > key; j -=gap)
                         nodeAtIndex(*head,j)->val= nodeAtIndex(*head,j-gap)->val;
                
             nodeAtIndex(*head,j)->val=key;
           }
     }
}
}


void dis(struct node *head)
{
    struct node *tem=head;
     printf("\nDll is : ");
     while(tem!=NULL)
      {
            printf("%d<->",tem->val);
            tem=tem->next;
      }
       printf("NULL\n");
}


void main()
{
   struct node *head=NULL;
   insert(&head,12);
       insert(&head,1);
     insert(&head,122);
     insert(&head,11);
       insert(&head,32);
      insert(&head,67);
     dis(head);
     sort(&head);
     dis(head);
}