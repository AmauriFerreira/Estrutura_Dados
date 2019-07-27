// fatecipirangaads2017@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"

int** new_matrix(int lines, int columns) {
    int** m = (int **) malloc(lines * sizeof(int*));
    assert(m);
    for (int i = 0; i != lines; ++i) {
        m[i] = (int *) malloc(columns * sizeof(int));
        assert(m[i]);
    }
    return m;
}
    
   

int main() {
    /*array as = new_array();
    for (int i = 1; i != 1000; ++i) as = array_add(as, i);
    for (array_it it = array_begin(as); it != array_end(as); it = it_next(it))
        fprintf(stderr, "%d ", it_get(it)); */

    /*for (int i = 0; i != array_size(as); ++i) 
        fprintf(stderr, "%d ", array_get(as, i)); */

    int **m = new_matrix(5, 5);
    for (int i = 0; i != 5; ++i)
        for (int j = 0; j != 5; ++j)
            m[i][j] = i * j;

    for (int i = 0; i != 5; ++i) {
        for (int j = 0; j != 5; ++j)
            fprintf(stderr, "%d ", m[i][j]);
        fprintf(stderr, "\n");
    }
}
