#include<stdio.h>
#include"postfix.h"
int main()
{
    char input[EXP_SIZE], postfix[EXP_SIZE];
    printf("==========================\n");
    printf("Welcome to Simple Calculator\n");
    printf("==========================\n");
    printf("Enter your Expression:\n");
    fgets(input, EXP_SIZE, stdin);
    int error;
    error = input_to_postfix(input, postfix);
    if(error > 0)
    {
        printf("Your expression is invalid. Please try again.\n");
        printf("===========================================================\n");
        return 0;
    }
    int result;
    result = evalute_postfix(postfix);
    if(result == INT_MAX)
    {
        printf("Your expression is invalid. Please try again.\n");
        printf("===========================================================\n");
        return 0;
    }
    printf("The answer for your expression is = %d\n", result);
    printf("Thank you for using our Calculator.\n");
    printf("===========================================================\n");
    return 0;
}
