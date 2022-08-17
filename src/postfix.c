#include<stdio.h>
#include "postfix.h"
#include "stack.h"
#include<string.h>
static int order(char ch);
void input_to_postfix(char input[EXP_SIZE],char postfix[EXP_SIZE])
{
    int i, p_index = 0;
    stack st;
    st.top = -1;

    for(i = 0; i < strlen(input); i++)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            postfix[p_index] = input[i];
            p_index++;
        }
        else if( input[i] =='(' )
        {
            int y;
            while( st.top ==')' )
            {
                y = pop(&st);
                postfix[p_index] = y;
                p_index++;
            }
        }
        else
        {
            if(st.top == -1)
            {
                push(&st, input[i]);
            }
            else {
                char x;
                x = pop(&st);
                if( order(x) < order(input[i]))
                {
                    push( &st , x);
                    push( &st , input[i]);
                } else {
                    char z = pop(&st);
                    while(order(z) >= order(input[i]))
                    {
                        postfix[p_index] = z;
                        z = pop(&st);
                        p_index++;
                    }
                    push( &st , input[i]);
                }
            }
        }
    }
}

static int order(char ch)
{
    if(ch == '/')
    {
        return 3;
    }
    else if(ch == '*')
    {
        return 2;
    }
    else if(ch == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

