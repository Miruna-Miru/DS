//Reverse string using stack
/*
Given a String. Reverse each word (using stack) in it where the words are separated by dots.
Input: S = "i.like.this.program.very.much"
Output: i.ekil.siht.margorp.yrev.hcum

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 40

char stack[MAX];
int top=-1;

int isEmpty()
{
   return(top==-1);
}


int isFull()
{
   return(top==MAX-1);
}


void push(char c)
{
   if(!isFull())
        stack[++top]=c;
  else
       printf("\nOverflow");
}

char pop()
{
   char c;
   if(!isEmpty())
   {
         c=stack[top];
          top--;
         return c;
   }
  else
        printf("\nUnderflow");
  return '$';
}



void reverse(char *str)
{
    int len=strlen(str),i;
    for(i=0;i<len;i++)
     {
        if(str[i]!='.')
           push(str[i]);
       else
         {
                while(!isEmpty())
                      printf("%c",pop());
                printf(".");
          }
    }
    while(!isEmpty())
           printf("%c",pop());
}


void main()
{
   char str[]="This.is.a.sample";
   reverse(str);
}