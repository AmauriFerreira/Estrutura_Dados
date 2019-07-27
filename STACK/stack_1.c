#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

stack new_stack(int length) {
    stack s;
    s.elems = (int *) malloc(length * sizeof(int));
    assert(s.elems);
    s.length = length;
    s.top = s.elems;
    return s;
}

void destroy_stack(stack s) {
    free(s.elems);
}

stack stack_push(stack s, int e) {
    assert(s.top != s.elems + s.length);
    *s.top++ = e;
    return s;
}

stack stack_pop(stack s) {
    assert(s.top != s.elems);
    s.top--;
    return s;
}

int stack_top(stack s) {
    assert(s.top != s.elems);
    return *(s.top-1);
}

int stack_empty(stack s) {
    return s.top == s.elems;
}









