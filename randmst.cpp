#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include "kruskal.h"
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
        addTheEdges(setOfPoints, numpoints, dimension, completeGraph);

        //the answer graph
        Graph* answer = kruskal(completeGraph, numpoints);

        //this doesn't really work right now
        //printAnswer(answer->adjacency, numpoints);

        cout << "The total weight is ";
        cout << answer->totalWeight() << endl;

        // cleanup memory
        for (unsigned int i = 0; i < setOfPoints.size(); i++) {
            delete(setOfPoints[i]);
        }
        
        vector<Edge*> edges = completeGraph->getEdges();
        for (unsigned int i = 0; i < edges.size(); i++) {
            delete(edges[i]);
        }
        delete(completeGraph);
        delete(answer);
    }
    return 0;
}
