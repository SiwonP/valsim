#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

struct Stack {
    void *el;
    Stack *next;
    Stack *prev;
};

#endif
