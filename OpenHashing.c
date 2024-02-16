//Open hashing (separate chaining)

#include<stdio.h>
#include<stdlib.h>

#define size 6

struct node
{
   int val;
   struct node *next;
};

struct node *chain[size];

struct node*newNode(int x)
{
    struct node *ne=(struct node*)malloc(sizeof(struct node));
    ne->val=x;
    ne->next=NULL;
   return ne;
}


void init()
{
    int i;
    for(i=0;i<size;i++)
         chain[i]=NULL;
}


void insert(int x)
{
   struct node *ne=newNode(x);
   int key;
   key=x%size;
   if(chain[key]==NULL)
           chain[key]=ne;
   else
   {
       struct node *tem=chain[key];
       while(tem->next!=NULL)
             tem=tem->next;
      tem->next=ne;
   }
}


void del(int x)
{
    struct node *tem, *prev = NULL;
    int key = x % size;
    tem = chain[key];

    while (tem != NULL)
    {
        if (tem->val == x)
        {
            if (prev == NULL)
            {
                // If the node to be deleted is the first node in the list
                chain[key] = tem->next;
            }
            else
                      prev->next = tem->next;
            free(tem);
            printf("\nNode del : %d\n ",x);
            return;
        }
        prev = tem;
        tem = tem->next;
    }

    printf("\nNode not found\n");
}
 

void ser(int x)
{
   int key=x%size;
   struct node *tem=chain[key];
   while(tem!=NULL)
   {
       if(tem->val==x)
        {
            printf("\nFound   :  %d\n",x);
            return;
        }
        tem=tem->next;
     }
   printf("\nNot found :   %d\n",x);
 }


void dis()
{
   struct node *tem;
   int i;
  for(i=0;i<size;i++)
  {
   tem=chain[i];
   while(tem!=NULL)
   {
        printf("%d->",tem->val);
        tem=tem->next;
    }
    printf("NULL\n");
  }
}


void main()
{
   init();
   insert(7);
  insert(2);
  insert(6);
  insert(8);
  insert(4);
  insert(10);
  dis();
  ser(1);
  ser(4);
  del(7);
  dis();
}
   
