#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node;

struct node {
   int val;
   node* next;
};

node* new_node(int val, node* next) {
    node* p = (node*) malloc(sizeof(node));
    assert(p);
    p->val = val; p->next = next;
    return p;
}


node* list_of_ints(int n) {
    assert(n >= 0);
    if (n == 0) return NULL;
    node* first = new_node(0, NULL);
    node* last = first;
    for (int i = 1; i != n; ++i) {
        node* p = new_node(i, NULL);
        last->next = p;
        last = p;
    }
    return first;
}

node* listof_ints(int n) {
    assert(n >= 0);
    node* first = NULL;
    while (--n >= 0) first = new_node(n, first);
    return first;
}

void list_print(node* p) {
    while (p != NULL) {
        fprintf(stderr, "%d ", p->val);
        p = p->next;
    }
    fprintf(stderr, "\n");
} 

node* list_max(node* p) {
    if (p == NULL) return NULL;
    node* m = p;
    for (node* r = p->next; r != NULL; r = r->next)
        if (r->val > m->val) m = r;
    return m;
}

node* list_min(node* p) {
    if (p == NULL || p->next == NULL) return p;
    node* m = list_min(p->next);
    return p->val < m->val ? p : m;
}

node* list_remove(int val, node* p) {
    node b;
    b.next = p;
    node* r;
    for (r = &b ; r->next != NULL && r->next->val != val; r = r->next);
    if (r->next == NULL) return b.next;
    node* rr = r->next;
    r->next = rr->next;
    free(rr);
    return b.next; 
}

node* list_remove_rec(int val, node* p) {
    if (p == NULL) return NULL;
    if (p->val == val) {
        node* pp = p->next;
        free(p);
        return pp;
    }
    p->next = list_remove_rec(val, p->next);
    return p;
}

int main() {
    node* p = listof_ints(10);
    list_print(p);
    node* m = list_max(p);
    fprintf(stderr, "\n maior valor: %d\n", m->val);
    p = list_remove(6, p);
    list_print(p);
    p = list_remove_rec(3, p);
    list_print(p);
}















