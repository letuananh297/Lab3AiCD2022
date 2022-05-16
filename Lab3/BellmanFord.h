#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include "..\\Lab 1 real real\List.h"

#define INF ((double)(1e300 * 1e300))

using namespace std;

class Edge {
public:
	string departureCity;
	string arrivalCity;
	double price;

	Edge() {
		this->departureCity = "";
		this->arrivalCity = "";
		this->price = INF;
	}

	Edge(string departureCity, string arrivalCity, double price) {
		this->departureCity = departureCity;
		this->arrivalCity = arrivalCity;
		this->price = price;
	}
};

List<Edge*>* getEdges(string fileName) {
	fstream f;
	List<Edge*>* edges = new List<Edge*>();
	f.open(fileName, ios::in);
	if (f.bad())
		cout << "Error while read file.";
	else {
		string line;
		string subLine;
		string::size_type pos = 0;
		while (getline(f, line)) {
			Edge* edge1 = new Edge();
			Edge* edge2 = new Edge();
			subLine = line;
			pos = line.find(';');
			subLine.resize(pos);
			edge1->departureCity = subLine;
			edge2->arrivalCity = subLine;
			line.erase(0, pos + 1);

			subLine = line;
			pos = line.find(';');
			subLine.resize(pos);
			edge1->arrivalCity = subLine;
			edge2->departureCity = subLine;
			line.erase(0, pos + 1);

			subLine = line;
			pos = line.find(';');
			subLine.resize(pos);
			if (subLine != "N/A") {
				edge1->price = stoi(subLine);
				edges->pushback(edge1);
			}
			line.erase(0, pos + 1);
			if (line != "N/A") {
				edge2->price = stoi(line);
				edges->pushback(edge2);
			}
		}
	}
	f.close();
	return edges;
}

List<string>* getVertices(List<Edge*>* edges) {
	List<string>* vertices = new List<string>();
	Element_List<Edge*>* temp = edges->head;
	while (temp != NULL) {
		if (!vertices->contain(temp->data->departureCity))
			vertices->pushback(temp->data->departureCity);
		if (!vertices->contain(temp->data->arrivalCity))
			vertices->pushback(temp->data->arrivalCity);
		temp = temp->next;
	}
	return vertices;
}

double** Bellman_Ford(List<Edge*>* edges, List<string>* vertices) {
	Element_List<string>* tempVertex = vertices->head;
	double** adjacencyMatrix = new double* [vertices->size];
	for (int i = 0; i < vertices->size; i++) {
		adjacencyMatrix[i] = new double[vertices->size];
	}
	for (int i = 0; i < vertices->size; i++) {
		for (int j = 0; j < vertices->size; j++) {
			if (i == j)
				adjacencyMatrix[i][j] = 0;
			else
				adjacencyMatrix[i][j] = INF;
		}
	}
	tempVertex = vertices->head;
	while (tempVertex != NULL) {
		Element_List<Edge*>* tempEdge = edges->head;
		while (tempEdge != NULL) {
			int i = 0, j = 0;
			i = vertices->getIndex(tempEdge->data->departureCity);
			j = vertices->getIndex(tempEdge->data->arrivalCity);
			for (int k = 0; k < vertices->size; k++) {
				if (adjacencyMatrix[k][i] + tempEdge->data->price < adjacencyMatrix[k][j])
					adjacencyMatrix[k][j] = adjacencyMatrix[k][i] + tempEdge->data->price;
			}
			tempEdge = tempEdge->next;
		}
		tempVertex = tempVertex->next;
	}
	return adjacencyMatrix;
}