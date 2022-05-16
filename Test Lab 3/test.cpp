#include "pch.h"
#include "gtest/gtest.h"
#include "..\Lab3\BellmanFord.h"

TEST(First_Test) {
	List<Edge*>* edges = getEdges("test.txt");
	Element_List<Edge*>* tempEdge = edges->head;
	ASSERT_EQ(tempEdge->data->departureCity, "Saint Petersburg");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Kazan");
	ASSERT_EQ(tempEdge->data->price, 20);
	tempEdge = tempEdge->next;

	ASSERT_EQ(tempEdge->data->departureCity, "Kazan");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Saint Petersburg");
	ASSERT_EQ(tempEdge->data->price, 10);
	tempEdge = tempEdge->next;

	ASSERT_EQ(tempEdge->data->departureCity, "Saint Petersburg");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Moscow");
	ASSERT_EQ(tempEdge->data->price, 20);
	tempEdge = tempEdge->next;

	ASSERT_EQ(tempEdge->data->departureCity, "Moscow");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Saint Petersburg");
	ASSERT_EQ(tempEdge->data->price, 30);
	tempEdge = tempEdge->next;

	ASSERT_EQ(tempEdge->data->departureCity, "Moscow");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Kazan");
	ASSERT_EQ(tempEdge->data->price, 70);

	List<string>* vertices = getVertices(edges);
	Element_List<string>* tempVertex = vertices->head;
	ASSERT_EQ(tempVertex->data, "Saint Petersburg");
	tempVertex = tempVertex->next;
	ASSERT_EQ(tempVertex->data, "Kazan");
	tempVertex = tempVertex->next;
	ASSERT_EQ(tempVertex->data, "Moscow");

	double** adjacencyMatrix = new double* [vertices->size];
	for (int i = 0; i < vertices->size; i++)
		adjacencyMatrix[i] = new double[vertices->size];
	adjacencyMatrix = Bellman_Ford(edges, vertices);
	ASSERT_EQ(adjacencyMatrix[0][0], 0);
	ASSERT_EQ(adjacencyMatrix[0][1], 20);
	ASSERT_EQ(adjacencyMatrix[0][2], 20);
	ASSERT_EQ(adjacencyMatrix[1][0], 10);
	ASSERT_EQ(adjacencyMatrix[1][1], 0);
	ASSERT_EQ(adjacencyMatrix[1][2], 30);
	ASSERT_EQ(adjacencyMatrix[2][0], 30);
	ASSERT_EQ(adjacencyMatrix[2][1], 50);
	ASSERT_EQ(adjacencyMatrix[2][2], 0);
}

TEST(Second_Test) {
	List<Edge*>* edges = getEdges("test2.txt");
	Element_List<Edge*>* tempEdge = edges->head;
	ASSERT_EQ(tempEdge->data->departureCity, "Saint Petersburg");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Moscow");
	ASSERT_EQ(tempEdge->data->price, 10);
	tempEdge = tempEdge->next;

	ASSERT_EQ(tempEdge->data->departureCity, "Moscow");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Saint Petersburg");
	ASSERT_EQ(tempEdge->data->price, 20);
	tempEdge = tempEdge->next;

	ASSERT_EQ(tempEdge->data->departureCity, "Moscow");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Khabarovsk");
	ASSERT_EQ(tempEdge->data->price, 40);
	tempEdge = tempEdge->next;

	ASSERT_EQ(tempEdge->data->departureCity, "Khabarovsk");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Moscow");
	ASSERT_EQ(tempEdge->data->price, 35);
	tempEdge = tempEdge->next;

	ASSERT_EQ(tempEdge->data->departureCity, "Saint Petersburg");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Khabarovsk");
	ASSERT_EQ(tempEdge->data->price, 14);
	tempEdge = tempEdge->next;

	ASSERT_EQ(tempEdge->data->departureCity, "Vladivostok");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Khabarovsk");
	ASSERT_EQ(tempEdge->data->price, 13);
	tempEdge = tempEdge->next;

	ASSERT_EQ(tempEdge->data->departureCity, "Khabarovsk");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Vladivostok");
	ASSERT_EQ(tempEdge->data->price, 8);
	tempEdge = tempEdge->next;

	ASSERT_EQ(tempEdge->data->departureCity, "Saint Petersburg");
	ASSERT_EQ(tempEdge->data->arrivalCity, "Vladivostok");
	ASSERT_EQ(tempEdge->data->price, 20);

	List<string>* vertices = getVertices(edges);
	Element_List<string>* tempVertex = vertices->head;
	ASSERT_EQ(tempVertex->data, "Saint Petersburg");
	tempVertex = tempVertex->next;
	ASSERT_EQ(tempVertex->data, "Moscow");
	tempVertex = tempVertex->next;
	ASSERT_EQ(tempVertex->data, "Vladivostok");
	tempVertex = tempVertex->next;
	ASSERT_EQ(tempVertex->data, "Khabarovsk");

	double** adjacencyMatrix = new double* [vertices->size];
	for (int i = 0; i < vertices->size; i++)
		adjacencyMatrix[i] = new double[vertices->size];
	adjacencyMatrix = Bellman_Ford(edges, vertices);
	ASSERT_EQ(adjacencyMatrix[0][0], 0);
	ASSERT_EQ(adjacencyMatrix[0][1], 10);
	ASSERT_EQ(adjacencyMatrix[0][2], 14);
	ASSERT_EQ(adjacencyMatrix[0][3], 20);
	ASSERT_EQ(adjacencyMatrix[1][0], 20);
	ASSERT_EQ(adjacencyMatrix[1][1], 0);
	ASSERT_EQ(adjacencyMatrix[1][2], 34);
	ASSERT_EQ(adjacencyMatrix[1][3], 40);
	ASSERT_EQ(adjacencyMatrix[2][0], 55);
	ASSERT_EQ(adjacencyMatrix[2][1], 35);
	ASSERT_EQ(adjacencyMatrix[2][2], 0);
	ASSERT_EQ(adjacencyMatrix[2][3], 8);
	ASSERT_EQ(adjacencyMatrix[3][0], 68);
	ASSERT_EQ(adjacencyMatrix[3][1], 48);
	ASSERT_EQ(adjacencyMatrix[3][2], 13);
	ASSERT_EQ(adjacencyMatrix[3][3], 0);
}