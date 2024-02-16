// Sum using LL


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
}


void insert(struct node **root,int x)
{
    struct node *tem=*root,*ne=newNode(x);
   if(*root==NULL)
         *root=ne;
   else
   {
      while(tem->next!=NULL)
             tem=tem->next;
      tem->next=ne;
   }
}



struct node *add(struct node *L1,struct node *L2)
{ 
          struct node *pre=NULL,*tem,*result=NULL;
           int carry=0,sum=0,x,y;
          while(L1 != NULL || L2!=NULL)
          {
               x=(L1!=NULL) ? L1->val : 0;
               y=(L2!=NULL) ? L2->val : 0;
               sum=carry+x+y;
               carry=sum/10;
              tem=newNode(sum%10);
              if(result==NULL)
                     result=tem;
             else
                  pre->next=tem;
            if(L1!=NULL)
                   L1=L1->next;
            if(L2!=NULL)
                   L2=L2->next;
            pre=tem;
            if(carry>0)
            {
                tem=newNode(x);
                pre->next=tem;
            }
           }
          return result;
}
  

struct node * reverse(struct node *List)
{
     struct node *pre=NULL,*current=List,*nex=NULL;
     while(current!=NULL)
      {
         nex=current->next;
         current->next=pre;   
         pre=current;
         current=nex;
      }
        return pre;
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


void main()
{
     struct node *L1=NULL,*L2=NULL,*res;
     insert(&L1,1);      
     insert(&L1,9);
     insert(&L1,0);
     insert(&L2,2);
     insert(&L2,5);
     
    L1= reverse(L1);
    L2=reverse(L2);
    res=add(L1,L2);
    res=reverse(res);
     dis(res);
}
             