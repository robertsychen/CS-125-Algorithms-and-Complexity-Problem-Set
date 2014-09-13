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

