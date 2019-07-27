#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"
#include "graph.h"

graph new_graph(int n) {
    graph G;
    G.n = n;
    G.adj = (array*) malloc(n * sizeof(array));
    assert(G.adj);
    return G;
}

void destroy_graph(graph G) {
    free(G.adj);
}

void add_edge(int x, int y, graph G) {
    G.adj[x] = array_add(G.adj[x], y);
    G.adj[y] = array_add(G.adj[y], x);
}

void graph_print(graph G) {
    for (int x = 0; x != G.n; ++x) {
        fprintf(stderr, "\n%d: ", x);
        for (array_it it = array_begin(G.adj[x]); 
             it != array_end(G.adj[x]);
             it = it_next(it)) {
            fprintf(stderr, "%d ", it_get(it));
        } 
    }
}

int main() {
    int n;
    scanf("%d", &n);
    graph G = new_graph(n);
    int x, y;
    while (scanf("%d%d", &x, &y) == 2) add_edge(x, y, G);
    graph_print(G);
}





























