#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "postfix.h"
#include "stack.h"
#include<string.h>
#include"int_stack.h"
static int order(char ch);
int input_to_postfix(char input[EXP_SIZE],char postfix[EXP_SIZE])
{

    stack st;
    st.top = -1;
    int i, p_index = 0, error = 0;
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

                postfix[p_index]=' ';
                p_index++;
                postfix[p_index] = y;
                p_index++;
                y = pop(&st);
            }
        }
        else if(input[i] == '(')
        {
            
            postfix[p_index]=' ';
            p_index++;
            push(&st, input[i]);
        }
        else
        {
            if(st.top == -1)
            {
                postfix[p_index]=' ';
                p_index++;
                push(&st, input[i]);
            }
            else {
                char x;
                x = pop(&st);
                if( order(x) < order(input[i]))
                {
                    postfix[p_index]=' ';
                    p_index++;
                    push( &st , x);
                    push( &st , input[i]);
                } else {
                    while(x != '\0' && order(x) >= order(input[i]))
                    {
                        postfix[p_index]=' ';
                        p_index++;
                        postfix[p_index] = x;
                        p_index++;
                        x = pop(&st);
                    }
                    if(x != '\0'){
                        postfix[p_index]=' ';
                        p_index++;
                        push(&st, x);
                    }
                    push( &st , input[i]);
                }
            }
        }
    }
    while (st.top != -1)
    {
        postfix[p_index]=' ';
        p_index++;
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
        return 4;
    }
    else if(ch == '*')
    {
        return 3;
    }
    else if(ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int evalute_postfix(char postfix[EXP_SIZE])
{
    Stack2 st2;
    st2.top=-1;
   int a,b,result,i;
   bool error=false;
   for(i=0;i<strlen(postfix);i++)
   {
       char temp_array[10];
       int p=0,q;
       if(isdigit(postfix[i])){
           while(postfix[i]!=' ')
               {
                   temp_array[p]=postfix[i];
                   p++;
                   i++;
               }
               temp_array[p]='\0';
               q=atoi(temp_array);
               int_push(&st2 , q);
        }
        else
        {
            if(postfix[i] == ' ' || postfix[i] == '\n')
                continue;
            a=int_pop(&st2);
            b=int_pop(&st2);
            switch(postfix[i])
            {
                case'+':
                    result=b+a;
                    break;
                case'-':
                    result=b-a;
                    break;
                case'*':
                    result=b*a;
                    break;
                case'/':
                    if(a != 0)
                        result=b/a;
                    else 
                        error = true;
                    break;
            }
            int_push(&st2 , result);
        }
   }
   if(st2.top == 0) {
       result = int_pop(&st2);
   }
   else
        error = true;
   if(error)
       result = INT_MAX;;
   return result;
}
