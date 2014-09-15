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

vector <Vertex*> createPoints(int numpoints, int dimension); 
void addTheEdges(vector <Vertex*> somepoints, int numpoints, int dimension, Graph* myGraph);
void printAnswer(vector<vector<double> > answerMatrix, int numpoints);
Graph* kruskal(Graph* graph1, int numpoints);

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

vector <Vertex*> createPoints(int numpoints, int dimension)
{
	//generates random coordinates for points, stored as vector of Vertexes
	vector <Vertex*> points(numpoints);
	cout << "Here are the coordinates of the vertices." << endl;
	for (int i = 0; i < numpoints; i++)
	{
		Vertex* aVertex = new Vertex(dimension);
		points[i] = aVertex;
		for (int j = 0; j < dimension; j++)
		{
			points[i]->value[j] = ((double) rand() / (RAND_MAX));
			cout << setw(10) << points[i]->value[j];
		}
		cout << endl;
	}

	return points;
}

void addTheEdges(vector <Vertex*> somepoints, int numpoints, int dimension, Graph* myGraph)
{
	//need to implement special case of dimension = 1...

	//uses Graph function to add edges into adjacency matrix, and prints weights in matrix
	cout << "Here is the adjacency matrix of edge weights." << endl;
	double squareddistance;
	for (int i = 0; i < numpoints; i++)
	{
		for (int j = 0; j < numpoints; j++)
		{
			squareddistance = 0;
			for (int k = 0; k < dimension; k++)
			{
				squareddistance += pow((somepoints[i]->value[k] - somepoints[j]->value[k]), 2);
			}
			Edge* thisEdge = new Edge();
			thisEdge->weight = sqrt (squareddistance);
			thisEdge->a = somepoints[i];
			thisEdge->b = somepoints[j];
			myGraph->addEdge(thisEdge);

			cout << std::setw(10) << thisEdge->weight;
		} 
		cout << endl;
	}
}

void printAnswer(vector<vector<double> > answerMatrix, int numpoints)
{
	//print out answer
	cout << "Here is a matrix depicting which edges are in the minimum spanning tree." << endl;
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

	for (int i = 0; i < numpoints; i++)
	{
		for (int j = 0; j < numpoints; j++)
		{
			cout << graph1->adjacency[i][j];
		}
		cout << endl;
	}

	Graph* spantree = new Graph(numpoints);
	spantree->num_vertices = numpoints;
	spantree->vertices = graph1->vertices;

	//fill adjacency matrix of spantree with zeroes
	vector<vector<double> > zeroMatrix(numpoints, vector<double>(numpoints));
	for (int i = 0; i < numpoints; i++)
	{
		for (int j = 0; j < numpoints; j++)
		{
			zeroMatrix[i][j] = 0;
		}
	}
	spantree->adjacency = zeroMatrix;

	vector<Edge*> edgearray = graph1->getEdges();
	vector<Vertex*> vertexarray = graph1->getVertices();

	//bubble sort the edges of the complete graph
	double numberofedges = (numpoints)*(numpoints - 1)*(0.5);
	double temp;
	for (int i = 0; i <= numberofedges-2; i++)             
	{
		for (int j = 0; j <= numberofedges-2; j++)
		{
			if (edgearray[j]->weight > edgearray[j+1]->weight)
			{
				temp = edgearray[j]->weight;                      
				edgearray[j]->weight = edgearray[j+1]->weight;
				edgearray[j+1]->weight = temp;
			}
		}
	}

	//make disjoint sets for all vertices
	for (int i = 0; i < numpoints; i++)
	{
		makeset(vertexarray[i]); //Why does this work?
	}

	for (int i = 0; i < numberofedges; i++)
	{
		if (edgearray[i]->a->set != edgearray[i]->b->set)
		{
			spantree->addEdge(edgearray[i]);

			cout << edgearray[i]->a << endl; //for testing
			cout << edgearray[i]->b << endl; // for testing
			cout << edgearray[i]->weight << endl; //for testing

			setunion(edgearray[i]->a->set, edgearray[i]->b->set); //Does this work?
			printAnswer (spantree->adjacency, numpoints);
		}
	}

	return spantree;
}
