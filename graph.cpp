#include <iostream>
#include <vector>
#include "graph.h"
#include "disjointset.h"
using namespace std;

Vertex::Vertex() {
    
}

Vertex::~Vertex() {
    if (set != NULL)
        delete(set);
}

Graph::Graph(int num_vertex) {
    V = num_vertex;
}

inline vector<Vertex*> Graph::getVertices() {
    return vertices;
}

inline vector<Edge*> Graph::getEdges() {

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

