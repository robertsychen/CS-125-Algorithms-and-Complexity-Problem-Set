#include <iostream> 
#include "disjointset.h"
#include "graph.h"
using namespace std;

DisjointSet::DisjointSet(Vertex* v) {
    // we must set the vertex's set
    v->set = this;

    vertex = v; 
    parent = this;
    rank = 0;
}

// parent(x)
DisjointSet* parent(DisjointSet* s) {
    return s->parent;
}

// rank(s)
int rank(DisjointSet* s) {
    return s->rank;
}

// find(x)
DisjointSet* find (DisjointSet* s) {
    if (s->vertex != s->parent->vertex) {
        DisjointSet* result = find(s->parent);
        s->parent = result;
        return result;
    } else {
        return s; 
    }
}

// makeset(v)
DisjointSet* makeset(Vertex* v) {
    return new DisjointSet(v);
}

// link(x,y)
DisjointSet* link(DisjointSet* x, DisjointSet* y) {
    if (x->rank > y->rank) {
        y->parent = x;
        return x;
    }
    else if (x->rank < y->rank) {
        x->parent = y;
        return y;
    }
    else { // x->rank == y-> rank
        y->rank++;
        x->parent = y;
        return y;
    }
}

// union(x,y)
DisjointSet* setunion(DisjointSet* x, DisjointSet* y) {
    return link(find(x), find(y));
}


