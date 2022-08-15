#define STACK_SIZE 100

struct Stack{
    char stack[STACK_SIZE];
    int top;
};

typedef struct Stack stack;
typedef struct Stack* stack_ptr;

void push(stack_ptr st, char num);
char pop(stack_ptr st);
void print(stack_ptr st);
