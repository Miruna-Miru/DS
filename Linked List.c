//Linked List


#include<stdio.h>

int x,i,ch=0;

struct node
{
    int data;
    struct node *next;
};


void insertF(struct node **head)
{
    printf("\nEnter element : ");
    scanf("%d",&x);
    struct node *ne=(struct node *)malloc(sizeof(struct node));
    ne->data=x;
    ne->next=(*head);
     *head=ne;
    printf("\nNode added");
}


void insertB(struct node **head,int pos)
{
    struct node *ne=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter element : ");
    scanf("%d",&x);
    ne->data=x;
    ne->next=NULL;
    struct node *temp=*head;
    while(--pos)
    {
        tem=tem->next;
        ne->next=tem->next;
        tem->next=ne;
     }
    printf("\nAdded successfully");
}


void insertE(struct node **head)
{
    struct node *tem=*head,*ne=(struct  node *)malloc(sizeof(struct node));
    printf("\nEnter element : ");
    scanf("%d",&x);
    while(tem->next!=NULL)
         tem=tem->next;
    tem->next=ne;
    ne->next=NULL;
    printf("\nNode added");
}



void deleteF(struct node **head)
{
    
    *head=(*head)->next;
     printf("\nNode deleted");
}



/*
void deleteB(struct node , int pos)
{
    struct node *tem=*head,
}
*/


void deleteE(struct node **head)
{
   struct node *tem=*head,*pre=NULL; 
   while(tem->next!=NULL)
   {
       pre=tem;
       tem=tem->next;
    }
   if(pre)
   {
       pre->next=NULL;
        free(tem);
       printf("\nNode deleted");
    }
 }


void dis(steuct node *head)
{
    while(head!=NULL)
    {
        printf("%d-->",node->data);
       head=head->next;
     }
   printf("\n");
}



int getlist(struct node *head)
{
    int size=0;
    while(head!=NULL)
     {
           size++;
           head=head->next;
     }
    return size;
}

void main()
{
   struct node *head=(struct node *)malloc(sizeof(struct node));
   head->next=NULL;
   printf("1-IF\t2-IB\t3-IE\t4-DF\t5-DE\t6-Dis\t7-Exit);
   while(ch!=7)
   {
      printf("\nEnter choice :   " );
      scanf("%d",&ch);
      switch(ch)
      {
           case 1 : 
                        insertF(&head);
                        break;
           case 2 :
                       printf("\nEnter pos : ");
                       scanf("%d",&i);
                       if(i<0 || i > getlist(head))
                              printf("\nInvalid position");
                       else 
                             insertB(&head,i);
                       break;
              case 3 :
                        insertE(&head);
                        break;
              case 4 :
                        deleteF(&head);
                        break;
               case 5 :
                        deleteE(&head);
                        break; 
            case 6 :
                        printf("\nLL IS: );
                        dis(head);
                        break;
             case 7 :
                       puts("\nExiting..........>"); 
                       break;
          }
}