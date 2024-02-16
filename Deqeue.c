//Deqeue

#include<stdio.h>
#include<stdlib.h>

#define MAX 20

int j,i;

int count(int arr[])
{
       int co=0;
       for(i=0;i<MAX;i++)
       {
            if(arr[i]!=0)
               co++;
        }
         return co;
} 


void dis(int arr[])
{
       printf("\nDequeue is : ");
       for(i=0;i<MAX;i++)
                  printf("%d ",arr[i]);
}


int isFull(int  *front_p,int *rear_p)
{
    return (*front_p==0 && *rear_p==MAX-1);
}

void addF(int arr[] , int x, int *front_p,int *rear_p)
{
   int si,k;
   if(isFull(front_p,rear_p))
  {
       printf("\nDequeqe full");
       return;
  }
  if(*front_p==-1)
  {
        *rear_p=*front_p=0;
         arr[*front_p]=x;
         printf("\nElement added at front");
         return;
  }
if(*rear_p!=MAX -1)
{
     si=count(arr);
     k=*rear_p+1;   
     for(i=0;i<=si;i++)
     {
        arr[k]=arr[k-1];
        k--;
      }
      arr[k]=x;
      printf("\nElement added at front");
      *front_p=x;
       (*rear_p)++;
}
else
{
    (*front_p)--;
    arr[*front_p]=x;
    printf("\nElement added at front");
}
}


void addE(int arr[] , int x, int *front_p,int *rear_p)
{
   int si,k;
   if(isFull(front_p,rear_p))
  {
       printf("\nDequeqe full");
       return;
  }
  if(*front_p==-1)
  {
        *rear_p=*front_p=0;
         arr[*front_p]=x;
         printf("\nElement added at front");
         return;
  }
if(*rear_p!=MAX -1)
{
     k = *front_p - 1;
    for (i = *front_p- 1; i < *rear_p; i++) {
      k = i;
      if (k == MAX - 1)
        arr[k] = 0;
      else
        arr[k] = arr[i + 1];
    }
    (*rear_p)--;
    (*front_p)--;
  }
  (*rear_p)++;
  arr[*rear_p] = x;
}
                
    int delFront(int *arr, int *pfront, int *prear) {
  int item;

  if (*pfront == -1) {
    printf("\nDeque is empty.\n");
    return 0;
  }

  item = arr[*pfront];
  arr[*pfront] = 0;

  if (*pfront == *prear)
    *pfront = *prear = -1;
  else
    (*pfront)++;

  return item;
}

int delRear(int *arr, int *pfront, int *prear) {
  int item;

  if (*pfront == -1) {
    printf("\nDeque is empty.\n");
    return 0;
  }

  item = arr[*prear];
  arr[*prear] = 0;
  (*prear)--;
  if (*prear == -1)
    *pfront = -1;
  return item;
}


void main()
{
      int front=-1,rear=-1,n,arr[MAX];
      for(i=0;i<MAX;i++)
            arr[i]=0;
 addE(arr, 5, &front, &rear);
  addF(arr, 12, &front, &rear);
  addE(arr, 11, &front, &rear);
  addF(arr, 5, &front, &rear);
  addE(arr, 6, &front, &rear);
  addF(arr, 8, &front, &rear);

  printf("\nElements in a deque: ");
  dis(arr);

  i = delFront(arr, &front, &rear);
  printf("\nremoved item: %d", i);

  printf("\nElements in a deque after deletion: ");
  dis(arr);

  addE(arr, 16, &front, &rear);
  addE(arr, 7, &front, &rear);

  printf("\nElements in a deque after addition: ");
  dis(arr);

  j= delRear(arr, &front, &rear);
  printf("\nremoved item: %d", j);

  printf("\nElements in a deque after deletion: ");
  dis(arr);

  n = count(arr);
  printf("\nTotal number of elements in deque: %d", n);
}

 

