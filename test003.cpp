#include <iostream>
#include <assert.h>
#include "kruskal.h"

using namespace std;

void test_smallCase();

int main(int argc, char** argv) {
    test_smallCase();
}

void test_smallCase() {
    Vertex* a = new Vertex(2);
    Vertex* b = new Vertex(2);
    Vertex* c = new Vertex(2);
    Vertex* d = new Vertex(2);

    Edge ab = {3, a, b};
    Edge bc = {6, b, c};
    Edge cd = {5, c, d};
    Edge ad = {1, a, d};
    Edge ac = {4, a, c};
    Edge bd = {2, b, d};

    Graph* g = new Graph(4);

    g->addEdge(&ab);
    g->addEdge(&bc);
    g->addEdge(&cd);
    g->addEdge(&ad);
    g->addEdge(&ac);
    g->addEdge(&bd);
    
    assert(g->totalWeight() == 21);
    
    Graph* mst = kruskal(g, 4);

    assert(mst->totalWeight() == 7);

    delete(a);
    delete(b);
    delete(c);
    delete(d);
    delete(g);
    delete(mst);
}
