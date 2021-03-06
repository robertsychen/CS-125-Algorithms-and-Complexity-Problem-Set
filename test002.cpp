#include <iostream>
#include <assert.h>
#include "kruskal.h"

using namespace std;

/**
 * tests for disjointset.cpp
 * 
 */

void disjointSetStuff();

int main() {
    disjointSetStuff();
    return 0;
}

void disjointSetStuff()
{
    Vertex* vertex1 = new Vertex(3);
    DisjointSet* set1 = new DisjointSet(vertex1);

    Vertex* vertex2 = new Vertex(3);
    DisjointSet* set2 = new DisjointSet(vertex2);

    Vertex* vertex3 = new Vertex(3);
    DisjointSet* set3 = new DisjointSet(vertex3);

    assert(vertex1->set == set1);
    assert(set1->vertex == vertex1);
    assert(set1->rank == 0);
    assert(set1->parent == set1);

    assert(find(set1) == set1);
    assert(find(set2) == set2);

    assert(link(set1, set2) == set2);

    assert(setunion(set1,set3) == set2);

    assert(set3->parent == set2);

    assert(find(set3) == set2);

    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

