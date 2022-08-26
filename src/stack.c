#include<stdio.h>
#include"stack.h"

void push(stack_ptr st,char num)
{
    if (st->top == (STACK_SIZE - 1))
      {
            printf ("Stack is Full\n");
      }
      else
      {
            st->top = st->top + 1;
            st->stack[st->top] = num;
      }

}

char pop(stack_ptr st)
{
      char num = '\0';;
      if (st->top == - 1)
      {
            return num;
      }
      else
      {
            num = st->stack[st->top];
            st->top = st->top - 1;
      }
      return(num);
}

void print(stack_ptr st)
{
    int i;
    if(st->top==-1)
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("Stack is\n");
        for(i = 0;i <= st->top; ++i) {
            printf("%c ", st->stack[i]);
        }
    }
}
