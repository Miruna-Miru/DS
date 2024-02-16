// Median in BST

#include<stdio.h>
#include<stdlib.h>


int arr[10],i=0,j;


struct node 
{
    int val;
    struct node *left,*right;
};


struct node *newNode(int x)
{
    struct node *ne=(struct node *)malloc(sizeof(struct node ));
   ne->val=x;
   ne->left=NULL;
   ne->right=NULL;
   return ne;
}


struct node *insert(struct node *root,int x)
{
    if(root==NULL)
         return newNode(x);
    else if (x>root->val)
         root->right=insert(root->right,x);
    else
          root->left=insert(root->left,x);
     return root;
}

void inorder(struct node *root)
{
    if(root==NULL)
          return;
    inorder(root->left);
    arr[i]=root->val;
    i++;
   inorder(root->right);
}


void sort(int n )
{
   int tem;
   for(i=0;i<n;i++)
   {
      for(j=i;j<n;j++)
      {
          if(arr[i]>arr[j])
          {
              tem=arr[i];
              arr[i]=arr[j];
               arr[j]=tem;
           }
      }
    }
}

void median(int n)
{
     int median;
     if(n%2==0)
         median=(arr[(n/2)]+arr[(n/2)-1])/2;
     else
         median=arr[n/2];
     printf("\nMedian is : %d",median);
}



void main()
{
   struct node *root=NULL;
   root=insert(root,2);
   root=insert(root,5);
   root=insert(root,7);
   root=insert(root,8);
   root=insert(root,4);
   root=insert(root,3);
   inorder(root);
   sort(5);
   median(5);
}
