//Postfix evaluation

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 30

int stk[MAX],i,j,top=-1;

int isEmpty()
{
   return (top==-1);
}

int isFull()
{
   return(top==MAX-1);
}

void push(int x)
{
    if(!isFull())
         stk[++top]=x;
    else
        printf("\nOverflow");
}


int pop()
{
   int c;
   if(!isEmpty()){
     c=stk[top];
     top--;
   }
   else 
 
       printf("\nUnderflow");
       return c;
}



int operator(char sy)
{
   return(sy=='+' || sy=='-' || sy=='/' ||sy=='*' || sy=='^');
}

int eval(char *exp)
{
  char sy;
  int op1,op2,re,num;
  i=0;
  sy=exp[i];
  while(sy!='\0')
  {
      if(sy>='0' && sy<='9')
       {
           num=sy-'0';
           push(num);
        }
       else if(operator(sy))
       {
              op1=pop();
              op2=pop();
              switch(sy)
              {
                    case '+':
                                  re=op1+op2;
                                  break;
                     case '-':
                                  re=op1-op2;
                                  break;
                   case '/' :
                                  re=op1/op2;
                                  break;
                   case '*' :
                                  re=op1*op2;
                                  break;
                   case '^' :
                                  re=pow(op1,op2); 
                                  break;
                   }
                   push(re);
              }
              i++;
             sy=exp[i];
             }
             re=pop();
             return re;
}


void main()
{
    char exp[]="52+";
     int re;
    re=eval(exp);
   printf("\nRedult : %d ",re);
}
                    
    
  