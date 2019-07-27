#include <stdlib.h>
#include <assert.h>
#include "array.h"

array new_array() {
    array as;
    as.elems = (int *) malloc(10 * sizeof(int));
    assert(as.elems);
    as.sz = 0;
    as.max_sz = 10;
    return as;
}

void destroy_array(array as) {
    free(as.elems);
} 

static array ensure_capacity(array as) {
    if (as.sz < as.max_sz) return as;
    array new_as;
    new_as.max_sz = 2 * as.max_sz;
    new_as.elems = (int *) malloc(new_as.max_sz * sizeof(int));
    assert(new_as.elems);
    for (int i = 0; i != as.sz; ++i) new_as.elems[i] = as.elems[i];
    free(as.elems);
    new_as.sz = as.sz;
    return new_as;
}

array array_add(array as, int e) {
    as = ensure_capacity(as);
    as.elems[as.sz] = e;
    ++as.sz;
    return as;
}

array array_pop(array as) {
    assert(0 < as.sz);
    --as.sz;
    return as;
}

int array_get(array as, int k) {
    assert(0 <= k && k < as.sz);
    return as.elems[k];
}

array array_put(array as, int k, int e) {
    assert(0 <= k && k < as.sz);
    as.elems[k] = e;
    return as;
}

int array_size(array as) { return as.sz; }

array_it array_begin(array as) { return as.elems; }

array_it array_end(array as) { return as.elems + as.sz; }

array_it it_next(array_it it) { return it + 1; }

int it_get(array_it it) { return *it; }






























