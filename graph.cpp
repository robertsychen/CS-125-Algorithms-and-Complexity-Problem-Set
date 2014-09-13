#include <iostream>
#include <vector>
using namespace std;

typedef int* Vertex;

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

Vertex::Vertex() {
    
}

Vertex::~Vertex() {
    if (set != null)
        delete(set);
}

Graph::Graph(int num_vertex) {
    V = num_vertex;
}

inline vector<Vertex*> Graph::getVertices() {
    return vertices;
}

inline vector<Edge*> Graph::getEdges() {
    int size = V;

    vector<Edge*> result ( V*(V-1)/2 );

    int index = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i+1; j < V; j++) {
            Edge* ed = new Edge();
            ed->weight = adjacency[i][j];
            ed->a = vertices[i];
            ed->b = vertices[j];
            result[index] = ed; 
        }
    }
    return result;
}

