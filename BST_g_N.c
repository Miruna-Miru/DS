//C program for a binary search tree (BST) and finding the largest element in the BST that is less than or equal to a given value N. .

#include<stdio.h>
#include<stdlib.h>


struct node {
   int val;
   struct node *left,*right;
};


int i;
struct node *newNode(int x)
{
 
    struct node *ne=(struct node *)malloc(sizeof(struct node));
   ne->val=x;
  ne->left=NULL;
  ne->right=NULL;
  return ne;
}


struct node *insert(struct node *root,int x)
{
      
   if(root==NULL)
      return  newNode(x);
  if(x>root->val)
       root->right=insert(root->right,x);
else if(x<root->val)
      root->left=insert(root->left,x);
   return root;
}


int grt(struct node *root,int x)
{
    int res=-1;
  while(root!=NULL){
    if(x>=root->val)
    {
        res=root->val;
        root=root->right;
     }
     else 
              root=root->left;
}
  return res;
}



void main()
{
    int x,n,r;
     struct node *root=NULL;
     printf("\nEnter no of node : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
            printf("\nEnter val : " );
            scanf("%d",&x);
            root=insert(root,x);
      }

printf("\nEnter vl to ser : ");
scanf("%d",&x);
r=grt(root,x);
if(r==-1)
    printf("\nNot matched ; -1");
else
   printf("\nGRT num is : %d",r);
}
    
   