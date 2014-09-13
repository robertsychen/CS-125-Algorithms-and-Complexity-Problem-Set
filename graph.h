#include <iostream>
#include <vector>
using namespace std;

class DisjointSet;

class Vertex {
    public:
        Vertex();
        ~Vertex();
        vector<int> value;
        DisjointSet* set;
};

class Edge {
    public:
        int weight;
        Vertex* a;
        Vertex* b;
};

class Graph {
    public:
        Graph(int); // constructor
        ~Graph(); // destructor
        int V;
        vector<Vertex*> vertices;
        vector< vector<int> > adjacency;

        vector<Vertex*> getVertices();
        vector<Edge*> getEdges();
};
