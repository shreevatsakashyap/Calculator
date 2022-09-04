
#define STACK_SIZE 100

struct Stack2{
    int stack[STACK_SIZE];
    int top;
};

typedef struct Stack2 stack2;
typedef struct Stack2* stack2_ptr;

void int_push(stack2_ptr st2, int num);
int int_pop(stack2_ptr st2);
void int_print(stack2_ptr st2);
