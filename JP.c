//Josephus using DLL

#include<stdio.h>
#include<stdlib.h>

struct node 
{
   int val;
   struct node *next,*pre;
};

int jp(int k,int n)
{
   int i,sur;
   struct node *head,*tem,*current;
   head=(struct node *)malloc(sizeof(struct node ));
   head->val=1;
   head->next=NULL;
   current = head;
   for(i=2;i<=n;i++)
   {
      struct node *ne=(struct node *)malloc(sizeof(struct node));
      ne->val=i;
      ne->pre=current;
      current->next=ne;
      current=ne;
    }

   current->next=head;
   head->pre=current;

  current=head;

  while(current->next!=current)
  {
     for(i=1;i<=k;i++)
            current=current->next;
    
     current->pre->next=current->next;
     current->next->pre=current->pre;
  
    tem=current;
   current=current->next;
     free(tem);

}

  sur=current->val;
  free(current);
  return sur;
}


void main()
{
   int k=2,n=5;
   printf("Survivor for n=%d and k=%d is : #%d",n,k,jp(k,n));
}
       
       