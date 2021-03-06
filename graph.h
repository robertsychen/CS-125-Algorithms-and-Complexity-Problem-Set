#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class DisjointSet;

class Vertex {
    public:
        Vertex(int);
        ~Vertex();
        vector<double> value;
        DisjointSet* set;
        int dimension;
        int index; // the index of the vertex in any graph
};

class Edge {
    public:
        double weight;
        Vertex* a;
        Vertex* b;
};

class Graph {
    public:
        Graph(int); // constructor
        ~Graph(); // destructor

        vector<Vertex*> vertices;

        //adjacency matrix code no longer necessary after revisions    
        //vector< vector<double> > adjacency;

        vector<Vertex*> getVertices();
        vector<Edge*> getEdges();

        void addEdge(Edge*);
        void addVertex(Vertex*);

        int numVertices(); // number of vertices
        int maxVertices(); //maximum number of vertices

        double totalWeight(); //weight of the graph

    protected:
        vector<Edge*> edges;
        int num_vertices;
        int max_vertices;
};
