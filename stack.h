#define STACK_SIZE 100

struct Stack{
    long stack[STACK_SIZE];
    int top;
};

typedef struct Stack stack;
typedef struct Stack* stack_ptr;

void push(stack_ptr st, long num);
long pop(stack_ptr st);
void print(stack_ptr st);
