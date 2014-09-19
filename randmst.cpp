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

    if (argc != 5) {
        cout << "4 arguments required. Program exiting." << endl;
        return 1;
    }
    int alg = atoi(argv[1]);
    int numpoints = atoi(argv[2]);
    int numtrials = atoi(argv[3]);
    int dimension = atoi(argv[4]);

    bool surpressOut = true;
    
    for (int i = 0; i < numtrials; i++)
    {
        vector <Vertex*> setOfPoints(numpoints);
        if (!surpressOut)
            cout << "Creating points" << endl;
        setOfPoints = createPoints(numpoints, dimension);
        if (!surpressOut)
            cout << "Created " << setOfPoints.size() << " vertices" << endl;

         
        //make a complete Graph
        Graph* completeGraph = new Graph(numpoints);
        if (!surpressOut)
            cout << "Creating complete graph" << endl;
        int* status = 
            addTheEdges(setOfPoints, numpoints, dimension, completeGraph, alg);

        if (!surpressOut)
            cout << "Created a graph with " << status[0] << " edges. Pruned "
            << status[1] << " edges." << endl;

        if (!surpressOut)
            cout << "Running Kruskal's algorithm" << endl;
        Graph* answer = kruskal(completeGraph, numpoints);

        //this doesn't really work right now
        //printAnswer(answer->adjacency, numpoints);

        if (!surpressOut) {
            if (answer != NULL) {
                cout << "Kruskal found a mst." << endl;
                cout << "The total weight is " << endl;
                cout << answer->totalWeight() << endl;

                cout << "Cleaning up memory" << endl;
            } else {
                cout << "No answer found.  Pruning was too aggressive."
                    << endl;
            }
        }
        // cleanup memory
        for (unsigned int i = 0; i < setOfPoints.size(); i++) {
            delete(setOfPoints[i]);
        }
       
        double max = 0;
        vector<Edge*> mst_edges = answer->getEdges();
        for (unsigned int i = 0; i < mst_edges.size(); i++) {
            if (mst_edges[i]->weight > max) {
                max = mst_edges[i]->weight; 
            }
        }

        if (answer != NULL)
            cout << max << "," << answer->totalWeight() << endl;
        else 
            cout << max << "," << "NA" << endl;

        vector<Edge*> edges = completeGraph->getEdges();
        for (unsigned int i = 0; i < edges.size(); i++) {
            delete(edges[i]);
        }
        delete(completeGraph);
        if (answer != NULL) 
            delete(answer);
    }
    return 0;
}
