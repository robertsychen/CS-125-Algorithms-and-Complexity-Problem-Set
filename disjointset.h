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

inline DisjointSet* makeSet(Vertex* v);
DisjointSet* link(DisjointSet* x, DisjointSet* y);
inline DisjointSet* setUnion(DisjointSet* x, DisjointSet* y);
