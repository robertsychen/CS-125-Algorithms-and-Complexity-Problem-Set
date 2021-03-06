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

    for (int i = 0; i < numpoints; i++)
    {
        Vertex* aVertex = new Vertex(dimension);
        points[i] = aVertex;
        for (int j = 0; j < dimension; j++)
        {
            points[i]->value[j] = ((double) rand() / (RAND_MAX));
        }
    }

    return points;
}

//frees edges which are sufficiently big to be disregarded
Edge* pruneEdge(Edge* edge, int numpoints, int dimension) {
    double weight = edge->weight;

    if (numpoints >= 65536) {
        if ((dimension == 1 && weight > 0.000331) ||
            (dimension == 2 && weight > 0.012877) ||
            (dimension == 3 && weight > 0.061914) ||
            (dimension == 4 && weight > 0.131187)) 
        {
           free(edge);
           return NULL;
        }
    }
    else if (numpoints > 32768) {
        if ((dimension == 1 && weight > 0.000628) ||
            (dimension == 2 && weight > 0.01673) ||
            (dimension == 3 && weight > 0.070706) ||
            (dimension == 4 && weight > 0.139354)) 
        {
           free(edge);
           return NULL;
        }
    }

    else if (numpoints >= 16384) {
        if ((dimension == 1 && weight > 0.00102294) ||
            (dimension == 2 && weight > 0.02307) ||
            (dimension == 3 && weight > 0.095375) ||
            (dimension == 4 && weight > 0.17278)) 
        {
           free(edge);
           return NULL;
        }
    }
    else if (numpoints >= 8192) {
        if ((dimension == 1 && weight > 0.001998) ||
            (dimension == 2 && weight > 0.031497) ||
            (dimension == 3 && weight > 0.103562) ||
            (dimension == 4 && weight > 0.211244)) 
        {
           free(edge);
           return NULL;
        }
    }
    else if (numpoints >= 5000) {
        if ((dimension == 1 && weight > 0.004005747) ||
            (dimension == 2 && weight > 0.040789) ||
            (dimension == 3 && weight > 0.134857) ||
            (dimension == 4 && weight > 0.236215)) 
        {
           free(edge);
           return NULL;
        }
    }
    return edge;
}

//creates Edges with given Vertexes as endpoints
//returns the number of edges that were added and the number pruned
int* addTheEdges(vector <Vertex*> somepoints, int numpoints, 
    int dimension, Graph* myGraph, int alg)
{
    int* result = new int[2];
    result[0] = 0;
    result[1] = 0;

    //treat special case of dimension = 0, which doesn't require finding Euclidean distance
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

    //adding edges, for all other dimensions
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
        } 
    }
    return result;
}

// will return NULL if kruskal failed, the graph otherwise.
Graph* kruskal(Graph* graph1, int numpoints)
{
    int spantree_edges = 0;
    Graph* spantree = new Graph(numpoints);

    vector<Edge*> edgearray = graph1->getEdges();
    double numberofedges = edgearray.size();

    vector<Vertex*> vertexarray = graph1->getVertices();

    sort(edgearray.begin(), edgearray.end(), compare());

    //make disjoint sets for all Vertexes
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
            spantree_edges++;
        }
    }
    
    if(spantree_edges != numpoints - 1) {
        // kruskal failed
        delete(spantree);
        return NULL;
    } else {
        return spantree;
    }
}
