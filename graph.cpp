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

double Graph::totalWeight() {
    double sum = 0;
    for (int i = 0; i < max_vertices; i++) {
        for (int j = i+1; j < max_vertices; j++) {
            sum += this->adjacency[i][j];
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

// add an edge to a graph
void Graph::addEdge(Edge* edge) {
    if (edge->a == edge->b) {
        return; //cannot have a connection to itself
    }

    int a_index = edge->a->index;
    int b_index = edge->b->index;

    vertices[a_index] = edge->a;
    vertices[b_index] = edge->b;

    adjacency[a_index][b_index] = edge->weight;
    adjacency[b_index][a_index] = edge->weight;
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
                result.push_back(ed); 
            }
        }
    }
    return result;
}
