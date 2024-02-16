#include<stdio.h>
#include<stdlib.h>

struct node
{
   int val;
   struct node *next;
};

struct node *front=NULL,*rear=NULL;

int x,i;

void en()
{
   printf("\nEnter val : ");
   scanf("%d",&x);
   struct node *ne=(struct node*)malloc(sizeof(struct node));
   ne->val=x;
   if(front == NULL && rear == NULL) {
       front=rear=ne;
   } else {
      rear->next=ne;
      rear=ne;
   }
}

void de()
{
     if(front==NULL)
     {
        printf("\nUnderflow");
         return;
     }
    else{
     struct node *tem=front;
     int te=front->val;
     front=front->next;
      free(tem);
     printf("\n%d is removed",te);
    }
}

void dis()
{
    struct node *tem=front;
    while(tem)
    {
        printf("%d ->",tem->val);
        tem=tem->next;
    }
}

int main()
{
    int choice;
    printf("\nImplementation of Queue using Linked List\n");
    while (1) {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                en();
                break;
            case 2:
                de();
                break;
            case 3:
                dis();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}
