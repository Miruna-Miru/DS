#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *newNode(int x) {
    struct node *ne = (struct node*)malloc(sizeof(struct node));
    ne->val = x;
    ne->next = NULL;
    return ne;
}

void insert(struct node **head, int x) {
    struct node *ne = newNode(x), *tem = *head;
    if (*head == NULL) {
        *head = ne;
    } else {
        while (tem->next != NULL)
            tem = tem->next;
        tem->next = ne;
    }
}

struct node *reverse(struct node *head) {
    struct node *pre, *current, *nex;
    current = head;
    pre = NULL;
    while (current != NULL) {
        nex = current->next;
        current->next = pre;
        pre = current;
        current = nex;
    }
    return pre;
}

void isPal(struct node *head) {
    int flag = 0;
    struct node *slow = head, *fast = head, *half;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    half = reverse(slow);
    while (half != NULL) {
        if (head->val != half->val){
            flag==0;
           break;
}
        flag++;
        head = head->next;
        half = half->next;
    }
    if (flag == 0)
        printf("\nNot palindrome");
    else
        printf("\nPalindrome");
}

int main() {
    struct node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    isPal(head);
    return 0;
}


       
      
   