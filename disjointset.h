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

inline DisjointSet* makeset(Vertex* v);
DisjointSet* link(DisjointSet* x, DisjointSet* y);
inline DisjointSet* setunion(DisjointSet* x, DisjointSet* y);
