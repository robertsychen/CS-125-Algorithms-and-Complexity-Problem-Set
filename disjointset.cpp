#include<iostream> 
using namespace std

typedef int* Vertex;

class DisjointSet {
    public:
        DisjointSet(Vertex); //constructor
        ~DisjointSet(); //destructor

        DisjointSet* find();

        DisjointSet* parent;
        int rank;
        Vertex* vertex;
}

DisjointSet::DisjointSet(Vertex* v) {
    vertex = v; 
    parent = v;
    rank = 0;
}

DisjointSet* DisjointSet::find () {
    if (vertex != parent->vertex) {
        return find(parent);
    } else {
        return &this; 
    }
}

inline DisjointSet* makeset(Vertex v) {
    return new DisjointSet(v);
}

DisjointSet* link(DisjointSet* x, DisjointSet* y) {
    if (x->rank > y->rank) {
        y.parent = x;
        return x;
    }
    else if (x->rank < y->rank) {
        x.parent = y;
        return y;
    }
    else { // x->rank == y-> rank
        y.rank++;
        x.parent = y;
        return y;
    }
}

DisjointSet* setunion(DisjointSet* x, DisjointSet* y) {
    return link(find(x), find(y));
}


