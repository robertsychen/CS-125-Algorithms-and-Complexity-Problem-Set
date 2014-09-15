#include <iostream>
#include <vector>
#include <map>
#include "graph.h"
#include "disjointset.h"
using namespace std;

Vertex::Vertex() {

}

Vertex::~Vertex() {
    if (set != NULL)
        delete(set);
}

Graph::Graph() {

}

Graph::~Graph() {
    //delete(&vertices);
    //delete(&adjacency);
}

// add a vertex to a graph.
void Graph::addVertex(Vertex* vertex) {
    // first, check if v is already in graph
    bool v_in_graph = false;
    for (unsigned int i = 0; i < vertices.size(); i++) {
        Vertex* v = vertices[i];
        if (v == vertex) {
            v_in_graph = true;
        }
    }

    if (v_in_graph) 
        return;
    
    int index = vertices.size();
    vertices[index] = vertex;
    vtoi[vertex] = index;
}

// add an edge to a graph
void Graph::addEdge(Edge* edge) {
    // first, check if either endpoints of the edges are already
    // in the graph
    bool a_in_graph = false;
    bool b_in_graph = false;

    // unfortunately this is O(n). TODO: optimize!!
    for (unsigned int i = 0; i < vertices.size(); i++) {
        cout << i << endl;
        Vertex* v = vertices[i];
        if (v == edge->a) {
            a_in_graph = true;
        }
        if (v == edge->b) {
            b_in_graph = true;
        }
    }
    
    int a_index = num_vertices;
    int b_index = num_vertices + 1;

    if (a_in_graph) {
        a_index = vtoi[edge->a];
        b_index = num_vertices;
    } else {
        vtoi[edge->a] = a_index;
        num_vertices++;
    }

    if (b_in_graph) { 
        b_index = vtoi[edge->b];
    } else {
        vtoi[edge->b] = b_index;
        num_vertices++;
    }
    
    vertices[a_index] = edge->a;
    vertices[b_index] = edge->b;

    adjacency[a_index][b_index] = edge->weight;
    adjacency[b_index][a_index] = edge->weight;
}

vector<Vertex*> Graph::getVertices() {
    return vertices;
}

vector<Edge*> Graph::getEdges() {

    vector<Edge*> result ( num_vertices*(num_vertices-1)/2 );

    int index = 0;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i+1; j < num_vertices; j++) {
            Edge* ed = new Edge();
            ed->weight = adjacency[i][j];
            ed->a = vertices[i];
            ed->b = vertices[j];
            result[index] = ed; 
        }
    }
    return result;
}

