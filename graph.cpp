#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <assert.h>
#include <string>
#include "graph.h"
#include "disjointset.h"
using namespace std;

Vertex::Vertex(int dim) {
    static int count = 0;
    dimension = dim;
    value.resize(dim);

    index = count;
    count++;
}

Vertex::~Vertex() {
    //if (set != NULL)
    //    delete(set);
}

Graph::Graph(int max_vert) {
    max_vertices = max_vert; 
    num_vertices = 0; 
    adjacency.resize(max_vertices);
    for (int i = 0; i < max_vertices; i++) {
        adjacency[i].resize(max_vertices);
    }
    vertices.resize(max_vertices);
}

Graph::~Graph() {

}

int Graph::totalWeight() {
    int sum = 0;
    for (int i = 0; i < max_vertices; i++) {
        for (int j = i+1; j < max_vertices; j++) {
            sum += adjacency[i][j];
        }
    }
    return sum;
}

int Graph::numVertices() {
    return num_vertices;
}

int Graph::maxVertices() {
    return max_vertices;
}

// add a vertex to a graph.
/*void Graph::addVertex(Vertex* vertex) {
    // first, check if v is already in graph
    bool v_in_graph = false;
    for (int i = 0; i < num_vertices; i++) {
        Vertex* v = vertices[i];
        if (v == vertex) {
            v_in_graph = true;
        }
    }

    if (v_in_graph) 
        return;
    
    vertices[num_vertices] = vertex;
    vtoi[vertex] = num_vertices;
    num_vertices++;
}*/

// add an edge to a graph
void Graph::addEdge(Edge* edge) {
    cout << "calling addEdge" << endl;
    if (edge->a == edge->b) {
        return; //cannot have a connection to itself
    }

    int a_index = edge->a->index;
    int b_index = edge->b->index;

    vertices[a_index] = edge->a;
    vertices[b_index] = edge->b;
    adjacency[a_index][b_index] = edge->weight;
    adjacency[b_index][a_index] = edge->weight;
    printf("adding edge (%u,%u)=%f\n", a_index, b_index,edge->weight);
}

vector<Vertex*> Graph::getVertices() {
    return vertices;
}

vector<Edge*> Graph::getEdges() {

    vector<Edge*> result;

    for (int i = 0; i < max_vertices; i++) {
        for (int j = i+1; j < max_vertices; j++) {
            double c = adjacency[i][j];

            if (c != 0) {
                Edge* ed = new Edge();
                ed->weight = c;
                ed->a = vertices[i];
                assert(i == ed->a->index);
                ed->b = vertices[j];
                assert(j == ed->b->index);
                cout << "(" << i << "," << j << ")e =" << c << endl;
                result.push_back(ed); 
            }
        }
    }
    return result;
}
