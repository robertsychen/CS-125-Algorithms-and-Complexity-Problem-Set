#include <vector>
#include "graph.h"
#include "disjointset.h"

using namespace std;

Graph* kruskal(Graph* g, int numpoints);
vector<Vertex*> createPoints(int numpoints, int dimension);
int* addTheEdges(vector<Vertex*> somepoints, int numpoints, 
    int dim, Graph* g, int alg);
void printAnswer(vector<vector<double> > answerMatrix, int numpoints);
Edge* pruneEdge(Edge* edge, int numpoints, int dimension);
