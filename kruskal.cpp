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
    cout << "Here are the coordinates of the vertices." << endl;
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

void addTheEdges(vector <Vertex*> somepoints, int numpoints, 
    int dimension, Graph* myGraph)
{
    //uses Graph function to add edges into adjacency matrix, 
    //and prints weights in matrix

    cout << "Here is the adjacency matrix of edge weights." << endl;

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
                myGraph->addEdge(thisEdge);
                cout << std::setw(10) << thisEdge->weight;
            }
            cout << endl;
        }
        return;
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
            myGraph->addEdge(thisEdge);

            //cout << std::setw(10) << thisEdge->weight;
        } 
        //cout << endl;
    }
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
    double numberofedges = (numpoints)*(numpoints - 1)*(0.5);
    vector<Edge*> edgearray = graph1->getEdges();
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
