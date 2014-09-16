#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include "graph.h"
#include "disjointset.h"
using namespace std;

int main(int argc, char **argv)
{
    srand (time(NULL));

    int numpoints = atoi(argv[2]);
    int numtrials = atoi(argv[3]);
    int dimension = atoi(argv[4]);

    for (int i = 0; i < numtrials; i++)
    {
        vector <Vertex*> setOfPoints(numpoints);
        setOfPoints = createPoints(numpoints, dimension);

        //make a complete Graph
        Graph* completeGraph = new Graph(numpoints);
        //completeGraph->num_vertices = numpoints;
        //completeGraph->vertices = setOfPoints;
        addTheEdges(setOfPoints, numpoints, dimension, completeGraph);

        Graph* answer = kruskal(completeGraph, numpoints);

        printAnswer(answer->adjacency, numpoints);
    }
    
    return 0;
}