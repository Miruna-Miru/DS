#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *left, *right;
};

struct node *newNode(int x) {
    struct node *ne = (struct node *)malloc(sizeof(struct node));
    ne->val = x;
    ne->left = ne->right = NULL;
    return ne;
}

struct node *insert(struct node **root, int x) {
    struct node *ne = newNode(x);
    if (*root == NULL)
        return ne;
    else if (x > (*root)->val)
        (*root)->right = insert(&((*root)->right), x);
    else
        (*root)->left = insert(&((*root)->left), x);
    return *root;
}

void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

struct node *del(struct node *root, int x) {
    struct node *tem;
    if (root == NULL)
        return NULL;
    if (x < root->val)
        root->left = del(root->left, x);
    else if (x > root->val)
        root->right = del(root->right, x);
    else {
        if (root->left == NULL) {
            tem = root->right;
            free(root);
            return tem;
        } else if (root->right == NULL) {
            tem = root->left;
            free(root);
            return tem;
        } else {
            tem = root->right;
            while (tem->left != NULL)
                tem = tem->left;
            root->val = tem->val;
            root->right = del(root->right, tem->val);
        }
    }
    return root;
}

int main() {
    struct node *root = NULL;
    root = insert(&root, 1);
    root = insert(&root, 3);
    root = insert(&root, 4);
    root = insert(&root, 2);
    root = insert(&root, 5);
    printf("\nOriginal: ");
    inorder(root);

    root = del(root, 2);
    printf("\nDeleted: ");
    inorder(root);

    root = del(root, 0); // Assuming you want to delete a node with value 0
    printf("\nDeleted: ");
    inorder(root);

    return 0;
}
