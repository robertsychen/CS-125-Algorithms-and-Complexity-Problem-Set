#include <vector>
#include "graph.h"
#include "disjointset.h"

using namespace std;

Graph* kruskal(Graph* g, int numpoints);
vector<Vertex*> createPoints(int numpoints, int dimension);
void addTheEdges(vector<Vertex*> somepoints, int numpoints, int dim, Graph* g);
void printAnswer(vector<vector<double> > answerMatrix, int numpoints);
