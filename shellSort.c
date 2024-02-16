// Shell sort

#include<stdio.h>



int i,j,tem,gap;

void sort(int n,int arr[])
{
  for(gap=n/2;gap>0;gap /=2)
  {
     for(i=gap;i<n;i++)
     {
         tem=arr[i];
         for(j=i;j>=gap && arr[j-gap]>tem;j -= gap)
              arr[j]=arr[j-gap];
         arr[j]=tem;
      }
  }
}


void main()
{
   int arr[]={54,62,12,1,432,23};
   sort(6,arr);
   for(i=0;i<6;i++)
        printf("%d--",arr[i]);
}
   