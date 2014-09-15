#include <iostream>
#include <assert.h>
#include "graph.h"

using namespace std;

void test_init();
void test_addVertex();
void test_addEdge1();
void test_addEdge2();

/**
 * Tests graph functions
 *
 */
int main(int argc, char** argv) {
    test_init();
    test_addVertex();
    test_addEdge1();
}

void test_init() {
    Graph* g = new Graph(10);
    assert((int)g->vertices.size() == g->max_vertices);
    assert((int)g->adjacency.size() == g->max_vertices);
    delete(g);
}

void test_addVertex() {
    Graph* g = new Graph(1002);

    for (int i = 0; i < 1000; i++) {
        Vertex* v = new Vertex(1);
        g->addVertex(v);
        assert(g->num_vertices == i+1);
    }

    for (int i = 0; i < 1000; i++) {
        Vertex* v = g->vertices[i];
        assert(g->vtoi[v] == i);

        g->addVertex(v);
        assert(g->num_vertices == 1000);
    }
    
    for (int i = 0; i < 1000;i++) {
        delete(g->vertices[i]);
    }
    delete(g);
}

void test_addEdge1() {
    Vertex* v1 = new Vertex(2);
    Vertex* v2 = new Vertex(2);

    Edge* edge = new Edge();
    edge->a = v1; 
    edge->b = v2;
    edge->weight = 0.5;

    Graph* g = new Graph(10);
    g->addEdge(edge);

    assert(g->num_vertices == 2);
    int index_a = g->vtoi[v1];
    int index_b = g->vtoi[v2];
    assert(g->adjacency[index_a][index_b] == edge->weight);
    assert(g->adjacency[index_b][index_a] == edge->weight);

    delete(g);
    delete(v1);
    delete(v2);
    delete(edge);
}
void test_addEdge2() {

}

void test_getEdges() {

}
