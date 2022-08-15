#include<stdio.h>
#include<postfix.h>
int main()
{
    char input[EXP_SIZE], postfix[EXP_SIZE];
    printf("enter the expression\n");
    gets(input);
    convert_to_postfix(input, postfix);
    return 0;
}
