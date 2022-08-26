#include<stdio.h>
#include"postfix.h"
int main()
{
    char input[EXP_SIZE], postfix[EXP_SIZE];
    printf("enter the expression\n");
    fgets(input, EXP_SIZE, stdin);
    int error;
    error = input_to_postfix(input, postfix);
    if(error > 0)
    {
        printf("invalid expression\n");
    }
    else{
        printf("the postfix expression is %s\n", postfix);
    }
    return 0;
}
