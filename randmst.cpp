#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;

int numpoints = atoi(argv[2]);
int dimension = atoi(argv[4]);

int main(int argc, char **argv)
{
	srand (time(NULL));

	double points[numpoints][dimension];
	for (int i = 0; i < numpoints; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			points[i][j] = ((double) rand() / (RAND_MAX));
			cout << setw(10) << points[i][j];
		}
		cout << endl;
	}

	double adjmatrix[numpoints][numpoints];
	double squareddistance;
	for (int i = 0; i < numpoints; i++)
	{
		for (int j = 0; j < numpoints; j++)
		{
			squareddistance = 0;
			for (int k = 0; k < dimension; k++)
			{
				squareddistance += pow((points[i][k] - points[j][k]), 2);
			}
			adjmatrix[i][j] = sqrt (squareddistance);
			cout << std::setw(10) << adjmatrix[i][j];

		}
		cout << endl;
	}
	//MAKE GRAPH OBJECT THING
	kruskal(graphA);
}

Graph kruskal(Graph graph1)
{
	Graph* spantree = new Graph();
	//make sure default has all the vertices?
	edgearray = spantree.getEdges();
	vertexarray = spantree.getVertices();

	for (int i = 0; i < numpoints; i++)
	{
		makeset(vertexarray[i]);
	}

	for (int i = 0; i < (numpoints * (numpoints - 1) / 2); i++)
	{
		if (edgearray[i].a.set != edgearray[i].b.set)
		{
			
		}
			//add the edge to Graph spantree
			//use setunion on those two disjoint sets
	}
	return spantree;
}
