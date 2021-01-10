// 인접 리스트로 구현한 DFS(깊이 우선 탐색)

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct Graph{ 
	int numOfVertex;
	int **matrix;
	int *visited;
}Graph;
Graph* makeGraph(int numOfVertex) {
	int i=0;
	Graph *graph = (Graph*)malloc(sizeof(Graph)*numOfVertex);
	graph->matrix = (int**)malloc(sizeof(int*)*numOfVertex);
	graph->visited = (int*)malloc(sizeof(int)*numOfVertex);
	graph->numOfVertex = numOfVertex;
	for(i=0; i<numOfVertex; i++) {
		graph->matrix[i] = (int*)malloc(sizeof(int)*numOfVertex);
		memset(graph->matrix[i], 0, sizeof(int)*numOfVertex);
		graph->visited[i] = 0;
	}
	return graph;
}

void addEdge(Graph* graph, int start, int end) {
	graph->matrix[start][end] = 1;
	graph->matrix[end][start] = 1;
}
void printGraph(Graph *graph) {
	int i, j;
	for (i = 0; i < graph->numOfVertex; i++) {
		printf("시작정점: %d ->", i);
		for (j = 0; j < graph->numOfVertex; j++) {
			printf("%d ", graph->matrix[i][j]);
		}
		printf("\n");
	}
}
void DFS(Graph* graph, int vertex) {
	int i = 0;
	graph->visited[vertex] = 1;
	printf("정점 %d 는 방문 됨\n", vertex);
	for (i = 0; i < graph->numOfVertex; i++) {
		if (graph->matrix[vertex][i] == 1 && graph->visited[i] == 0) {
			DFS(graph, i);
		}
	}
}

int main(void) {
	Graph * graph;
	graph = makeGraph(8);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 3, 7);
	addEdge(graph, 4, 7);
	addEdge(graph, 2, 5);
	addEdge(graph, 2, 6);
	addEdge(graph, 6, 7);
	addEdge(graph, 5, 7);
	printGraph(graph);
	DFS(graph, 0);
	return 0;
}