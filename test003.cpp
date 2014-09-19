#include <iostream>
#include <assert.h>
#include "kruskal.h"

using namespace std;

//Some tests on operations for Edges and Vertexes in a Graph

void test_smallCase();
void test_smallCase2();

int main(int argc, char** argv) {
    test_smallCase();
    test_smallCase2();
}

void test_smallCase() {
    Vertex* a = new Vertex(2);
    Vertex* b = new Vertex(2);
    Vertex* c = new Vertex(2);
    Vertex* d = new Vertex(2);

    Edge ab = {1, a, b};
    Edge ac = {3, a, c};
    Edge ad = {6, a, d};
    Edge bc = {2, b, c};
    Edge bd = {4, b, d};
    Edge cd = {5, c, d};

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

void test_smallCase2() {
    Vertex* a = new Vertex(2);
    Vertex* b = new Vertex(2);
    Vertex* c = new Vertex(2);
    Vertex* d = new Vertex(2);
    Vertex* e = new Vertex(2);

    Edge ab = {1, a, b};
    Edge ac = {3, a, c};
    Edge ad = {6, a, d};
    Edge ae = {7, a, e};
    Edge bc = {2, b, c};
    Edge bd = {4, b, d};
    Edge be = {8, b, e};
    Edge cd = {5, c, d};
    Edge ce = {9, c, e};
    Edge de = {10, d, e};

    Graph* g = new Graph(5);

    g->addEdge(&ab);
    g->addEdge(&bc);
    g->addEdge(&cd);
    g->addEdge(&ad);
    g->addEdge(&ac);
    g->addEdge(&bd);
    g->addEdge(&ae);
    g->addEdge(&be);
    g->addEdge(&ce);
    g->addEdge(&de);
    
    assert(g->totalWeight() == 55);
    
    Graph* mst = kruskal(g, 5);

    assert(mst->totalWeight() == 14);

    delete(a);
    delete(b);
    delete(c);
    delete(d);
    delete(e);
    delete(g);
    delete(mst);
}
