#include <iostream> 
using namespace std;

typedef int* Vertex;

class DisjointSet {
    public:
        DisjointSet(Vertex*); //constructor
        ~DisjointSet(); //destructor

        DisjointSet* parent;
        int rank;
        Vertex* vertex;
};

DisjointSet::DisjointSet(Vertex* v) {
    vertex = v; 
    parent = this;
    rank = 0;
}

// parent(x)
inline DisjointSet* parent(DisjointSet* s) {
    return s->parent;
}

// rank(s)
inline int rank(DisjointSet* s) {
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
inline DisjointSet* makeset(Vertex* v) {
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
inline DisjointSet* setunion(DisjointSet* x, DisjointSet* y) {
    return link(find(x), find(y));
}


