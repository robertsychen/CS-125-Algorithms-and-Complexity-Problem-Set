#include <iostream> 
using namespace std;

class Vertex;
class DisjointSet {
    public:
        DisjointSet(Vertex*); //constructor

        DisjointSet* parent;
        int rank;
        Vertex* vertex;
};

DisjointSet* find(DisjointSet* x);
DisjointSet* makeset(Vertex* v);
DisjointSet* link(DisjointSet* x, DisjointSet* y);
DisjointSet* setunion(DisjointSet* x, DisjointSet* y);
