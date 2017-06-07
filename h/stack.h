typedef struct Stack Stack;

struct Stack {
    void *el;
    Stack *next;
    Stack *prev;
};
