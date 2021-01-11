// 다익스트라 알고리즘
#include<stdio.h>

#define FALSE 0
#define TRUE 1
#define INF 10000000	// 무한대 표현
const int num = 6;

int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

int v[6]; // 방문한 노드
int d[6]; // 거리

// 가장 최소 거리를 가지는 정점을 반환
int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < num; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < num; i++)
		d[i] = a[start][i];
	v[start] = TRUE;
	for (int i = 0; i < num - 2; i++) {
		int current = getSmallIndex();
		v[current] = TRUE;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j])	// 다이나믹 프로그래밍의 구조입니다
					d[j] = d[current] + a[current][j];
			}
		}
	}
}

int main(void) {
	dijkstra(0);
	for (int i = 0; i < num; i++)
		printf("%d ", d[i]);
}