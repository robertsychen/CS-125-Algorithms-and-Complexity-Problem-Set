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

int numpoints = atoi(argv[2]);
int numtrials = atoi(argv[3]);
int dimension = atoi(argv[4]);

class Vertex;

vector <Vertex*> createPoints(); //correct syntax?
vector<vector<double>> createAdjMatrix(vector <Vertex*> somepoints); //correct syntax?
void printAnswer(vector<vector<double>> answerMatrix); //correct syntax?
Graph kruskal(Graph graph1);

int main(int argc, char **argv)
{
	for (int i = 0; i < numtrials; i++)
	{
		vector <Vertex*> setOfPoints(numpoints) = createPoints();
		vector<vector<double>> newMatrix(numpoints, vector<double>(numpoints)) = createAdjMatrix(setOfPoints);

		//make a complete Graph
		Graph* completeGraph = new Graph();
		completeGraph.adjacency = newMatrix;
		completeGraph.num_vertices = numpoints;
		completeGraph.vertices = setOfPoints;

		Graph* answer = kruskal(completeGraph);

		printAnswer(answer.adjacency);
	}
	
	return 0;
}

vector <Vertex*> createPoints() //correct syntax?
{
	srand (time(NULL)); //Where should this go?

	//generates random coordinates for points, stored as vector of Vertexes
	vector <Vertex*> points(numpoints);
	cout << "Here are the coordinates of the vertices." << endl;
	for (int i = 0; i < numpoints; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			points[i].value[j] = ((double) rand() / (RAND_MAX));
			cout << setw(10) << points[i].value[j];
		}
		cout << endl;
	}

	return points;
}

vector<vector<double>> createAdjMatrix(vector <Vertex*> somepoints)
{
	//need to implement special case of dimension = 1...

	//fills vector of a vector with edge weights
	vector<vector<double>> adjmatrix(numpoints, vector<double>(numpoints));
	double squareddistance;
	cout << "Here is the adjacency matrix of edge weights." << endl;
	for (int i = 0; i < numpoints; i++)
	{
		for (int j = 0; j < numpoints; j++)
		{
			squareddistance = 0;
			for (int k = 0; k < dimension; k++)
			{
				squareddistance += pow((somepoints[i][k] - somepoints[j][k]), 2);
			}
			adjmatrix[i][j] = sqrt (squareddistance);
			cout << std::setw(10) << adjmatrix[i][j];

		}
		cout << endl;
	}

	return adjmatrix;
}

void printAnswer(vector<vector<double>> answerMatrix) //correct syntax?
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

Graph kruskal(Graph graph1)
{
	Graph* spantree = new Graph();
	spantree.num_vertices = numpoints;
	spantree.vertices = graph1.vertices;

	//fill adjacency matrix of spantree with zeroes
	vector<vector<double>> zeroMatrix(numpoints, vector<double>(numpoints));
	for (int i = 0; i < numpoints; i++)
	{
		for (int j = 0; j < numpoints; j++)
		{
			zeroMatrix[i][j] = 0;
		}
	}
	spantree.adjacency = zeroMatrix;

	vector<Edge*> edgearray = graph1.getEdges();

	//bubble sort the edges of the complete graph
	int numberofedges = (numpoints)*(numpoints - 1)*(0.5);
	double temp;
	for (int i = 0; i <= numberofedges-1; i++)             
	{
		for (int j = 1; j <= numberofedges-1; j++)
		{
			if (edgearray[j] > edgearray[j+1])
			{
				temp = edgearray[j];                      
				edgearray[j] = edgearray[j+1];
				edgearray[j+1] = temp;
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
		if (edgearray[i].a.set != edgearray[i].b.set)
		{
			spantree.addEdge(edgearray[i]);
			setunion(edgearray[i].a.set, edgearray[i].b.set) //Does this work?
		}
	}

	return spantree;
}
