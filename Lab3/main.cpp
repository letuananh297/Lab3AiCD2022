#include<iostream>
#include <fstream>
#include"BellmanFord.h"
#include"..\\Lab 1 real real\List.h"

#define INF ((double)(1e300 * 1e300))

using namespace std;

int main() {
	List<Edge*>* edges = getEdges("cities.txt");
	List<string>* vertices = getVertices(edges);
	double** adjacencyMatrix = new double* [vertices->size];
	for (int i = 0; i < vertices->size; i++) {
		adjacencyMatrix[i] = new double[vertices->size];
	}
	adjacencyMatrix = Bellman_Ford(edges, vertices);
	string from, to;
	cout << "Enter city, where are you from: ";
	getline(cin, from);
	if (!vertices->contain(from))
		throw invalid_argument("There is not such city in the list.");
	cout << "Enter city, where you want to come to: ";
	getline(cin, to);
	if (!vertices->contain(from))
		throw invalid_argument("There is not such city in the list.");
	if (adjacencyMatrix[vertices->getIndex(from)][vertices->getIndex(to)] == INF)
		cout << "Not available to fly from " << from << " to " << to << endl;
	else
		cout << "\nThe lowest price to fly from " << from << " to " << to << " is: " << adjacencyMatrix[vertices->getIndex(from)][vertices->getIndex(to)] << endl;
	delete[] adjacencyMatrix;
	return 0;
}