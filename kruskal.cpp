#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "kruskal.h"
using namespace std;

//used in order to perform edge weight sorting
struct compare {
    bool operator()(const Edge* lhs, const Edge* rhs) const {
         return lhs->weight < rhs->weight;
    }
};

vector <Vertex*> createPoints(int numpoints, int dimension)
{
    //generates random coordinates for points, stored as vector of Vertexes

    //treat special case of dimension = 0
    if (dimension == 0)
    {
        dimension = 1;
    }

    vector <Vertex*> points(numpoints);
    //cout << "Here are the coordinates of the vertices." << endl;
    for (int i = 0; i < numpoints; i++)
    {
        Vertex* aVertex = new Vertex(dimension);
        points[i] = aVertex;
        for (int j = 0; j < dimension; j++)
        {
            points[i]->value[j] = ((double) rand() / (RAND_MAX));
            //cout << setw(10) << points[i]->value[j];
        }
        //cout << endl;
    }

    return points;
}

Edge* pruneEdge(Edge* edge, int numpoints, int dimension) {
    double weight = edge->weight;
    if (numpoints >= 5000) {
        if ((dimension == 1 && weight > 0.00456) ||
            (dimension == 2 && weight > 0.055) ||
            (dimension == 3 && weight > 0.164) ||
            (dimension == 4 && weight > 0.3)) 
        {
           free(edge);
           return NULL;
        }
    }
    return edge;
}

// returns the number of edges that were added and the number pruned
int* addTheEdges(vector <Vertex*> somepoints, int numpoints, 
    int dimension, Graph* myGraph, int alg)
{
    int* result = new int[2];
    result[0] = 0;
    result[1] = 0;
    //uses Graph function to add edges into adjacency matrix, 
    //and prints weights in matrix

    //cout << "Here is the adjacency matrix of edge weights." << endl;

    //treat special case of dimension = 0
    if (dimension == 0)
    {
        for (int i = 0; i < numpoints; i++)
        {
            for (int j = i+1; j < numpoints; j++)
            {
                Edge* thisEdge = new Edge();
                thisEdge->weight = ((double) rand() / (RAND_MAX));
                thisEdge->a = somepoints[i];
                thisEdge->b = somepoints[j];

                if (alg == 1)
                    thisEdge = pruneEdge(thisEdge, numpoints, dimension);

                if (thisEdge != NULL) {
                    myGraph->addEdge(thisEdge);
                    result[0]++;
                } else {
                    result[1]++;
                }
            }
        }
        return result;
    }

    double squareddistance;
    for (int i = 0; i < numpoints; i++)
    {
        for (int j = i+1; j < numpoints; j++)
        {
            squareddistance = 0;
            for (int k = 0; k < dimension; k++)
            {
                squareddistance += 
                    pow((somepoints[i]->value[k] - somepoints[j]->value[k]), 2);
            }
            Edge* thisEdge = new Edge();
            thisEdge->weight = sqrt (squareddistance);
            thisEdge->a = somepoints[i];
            thisEdge->b = somepoints[j];

            if (alg == 1)
                thisEdge = pruneEdge(thisEdge, numpoints, dimension);

            if (thisEdge != NULL) {
                myGraph->addEdge(thisEdge);
                result[0]++;
            } else {
                result[1]++;
            }

            //cout << std::setw(10) << thisEdge->weight;
        } 
        //cout << endl;
    }
    return result;
}

void printAnswer(vector<vector<double> > answerMatrix, int numpoints)
{
    //print out answer
    cout << "Here is a matrix depicting which edges "
        "are in the minimum spanning tree." << endl;
    for (int i = 0; i < numpoints; i++)
    {
        for (int j = 0; j < numpoints; j++)
        {
            cout << std::setw(10) << answerMatrix[i][j];
        }
        cout << endl;
    }
}

Graph* kruskal(Graph* graph1, int numpoints)
{
    Graph* spantree = new Graph(numpoints);
    //double numberofedges = (numpoints)*(numpoints - 1)*(0.5);
    vector<Edge*> edgearray = graph1->getEdges();
    double numberofedges = edgearray.size();
    vector<Vertex*> vertexarray = graph1->getVertices();

    sort(edgearray.begin(), edgearray.end(), compare());

    //make disjoint sets for all vertices
    for (int i = 0; i < numpoints; i++)
    {
        makeset(vertexarray[i]);
    }

    for (int i = 0; i < numberofedges; i++)
    {
        if (find(edgearray[i]->a->set) != find(edgearray[i]->b->set))
        {
            spantree->addEdge(edgearray[i]);
            setunion(edgearray[i]->a->set, edgearray[i]->b->set);
        }
    }
    
    return spantree;
}
