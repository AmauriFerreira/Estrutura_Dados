#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct stack stack;

struct stack {
    int *elems;
    int length;
    int idx;
};

stack *new_stack(int length) {
    stack *s = (stack *) malloc(sizeof(stack));
    assert(s);
    s->elems = (int *) malloc(length * sizeof(int));
    assert(s->elems);
    s->length = length;
    s->idx = 0;
    return s;
}

void destroy_stack(stack *s) {
    free(s->elems);
    free(s);
}

void stack_push(stack *s, int e) {
    assert(s->idx != s->length);
    s->elems[s->idx++] = e;
}

void stack_pop(stack *s) {
    assert(s->idx != 0);
    s->idx--;
}

int stack_top(stack *s) {
    assert(s->idx != 0);
    return s->elems[s->idx-1];
}

int stack_empty(stack *s) {
    return s->idx == 0;
}

int main() {
    stack *s = new_stack(10);    
    for (int i = 0; i != 10; ++i) stack_push(s, i);
    while (!stack_empty(s)) {
        printf("%d ", stack_top(s));
        stack_pop(s);
    }
    destroy_stack(s);
}








