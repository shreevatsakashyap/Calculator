#include<stdio.h>
#include"int_stack.h"

void int_push(stack2_ptr st2,int num)
{
    if (st2->top == (STACK_SIZE - 1))
    {
        printf ("Stack is Full\n");
    }
    else
    {
        st2->top = st2->top + 1;
        st2->stack[st2->top] = num;
    }

}

int int_pop(stack2_ptr st2)
{
    int num = -9999;;
    if (st2->top == - 1)
    {
        return num;
    }
    else
    {
        num = st2->stack[st2->top];
        st2->top = st2->top - 1;
    }
    return(num);
}

void int_print(stack2_ptr st2)
{
    int i;
    if(st2->top==-1)
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("Stack is\n");
        for(i = 0;i <= st2->top; ++i) {
            printf("%d ", st2->stack[i]);
        }
        printf("\n");
    }
}

