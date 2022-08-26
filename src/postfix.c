#include<stdio.h>
#include "postfix.h"
#include "stack.h"
#include<string.h>
static int order(char ch);
int input_to_postfix(char input[EXP_SIZE],char postfix[EXP_SIZE])
{
    int i, p_index = 0, error = 0;
    stack st;
    st.top = -1;

    for(i = 0; i < strlen(input); i++)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            postfix[p_index] = input[i];
            p_index++;
        }
        else if( input[i] ==')' )
        {
            int y=pop(&st);
            while( y != '\0' && y != '(' )
            {
                postfix[p_index] = y;
                p_index++;
                y = pop(&st);
            }
        }
        else if(input[i] == '(')
        {
            push(&st, input[i]);
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
                    while(x != '\0' && order(x) > order(input[i]))
                    {
                        postfix[p_index] = x;
                        x = pop(&st);
                        p_index++;
                    }
                    if(x != '\0')
                        push(&st, x);
                    push( &st , input[i]);
                }
            }
        }
    }
    while (st.top != -1)
    {
        char p = pop(&st);
        if(p == '(')
        {
           error++;
        }
        postfix[p_index] = p ;
        p_index++;

    }
    postfix[p_index] = '\0';
    return error;
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
    else if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

