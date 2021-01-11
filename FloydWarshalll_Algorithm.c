//플로이드-와셜 알고리즘
#include<stdio.h>

#define INF 10000000	// 무한대 표현
const int num = 4;

// 배열 초기화
int a[4][4] = {
	{0, 2, INF, 7},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall() {
	// 결과 그래프 초기화
	int result[4][4];

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			result[i][j] = a[i][j];
	}

	// k = 거쳐가는 노드
	for (int k = 0; k < num; k++) {
		// i = 출발 노드
		for (int i = 0; i < num; i++) {
			// j = 도착 노드
			for (int j = 0; j < num; j++) {
				if (result[i][k] + result[k][j] < result[i][j])	// 다이나믹 프로그래밍의 구조입니다
					result[i][j] = result[i][k] + result[k][j];	// k를 거쳐간다는 것을 표현
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			printf("%3d ", result[i][j]);
		printf("\n");
	}
}

int main(void) {
	floydWarshall();
}