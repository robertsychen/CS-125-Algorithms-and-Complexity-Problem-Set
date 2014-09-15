#include <iostream>
#include <assert.h>
#include "graph.h"

using namespace std;

void testGraphInit();
void testVertexAddition();

/**
 * Tests graph functions
 *
 */
int main(int argc, char** argv) {
    testGraphInit();
    testVertexAddition();
}

void testGraphInit() {
    Graph* g = new Graph();
    assert(g->vertices.size() == 0);
    assert(g->adjacency.size() == 0);
    delete(g);
}

void testVertexAddition() {
    Graph* g = new Graph();

    for (int i = 0; i < 1000; i++) {
        Vertex* v = new Vertex();
        g->addVertex(v);
        assert(g->vertices.size() == i+1);
    }

    delete(g);
}
