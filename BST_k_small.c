//Kth smallest in BST

#include<stdio.h>
#include<stdlib.h>

struct node 
{
  int val;
  struct node *left,*right;
};


struct node *newNode(int x)
{ 
    struct node *ne=(struct  node *)malloc(sizeof(struct node));
   ne->val=x;
   ne->left=ne->right=NULL;
  return ne;
}


struct node *insert(struct node *root,int x)
{
     
     if(root==NULL)
           return newNode(x);
     if(x>root->val)
        root->right=insert(root->right,x);
     else if(x<root->val)
         root->left=insert(root->left,x);
    return root;
}


void findK(struct node *root,int *count,int *result,int k)
{
 if (root == NULL || *count >= k) 
        return;
    

    // Traverse the left subtree
   findK(root->left, count, result,k);

    // Increment count as we visit a node
    (*count)++;

    // If the current node is the kth smallest, update the result
    if (*count == k) {
        *result = root->val;
        return;
    }

    // Traverse the right subtree
   findK(root->right, count, result,k);
}

void main()
{
  struct node *root=NULL;
   int count=0,result=-1,k=2;
   root=insert(root,7);
  root=insert(root,2);
  root=insert(root,8);
  root=insert(root,12);
  root=insert(root,22);
  root=insert(root,1);
  root=insert(root,4);
  findK(root,&count,&result,k);
  printf("\n%dth smallest is : %d",k,result);
}