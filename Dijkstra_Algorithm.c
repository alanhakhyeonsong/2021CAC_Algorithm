// ���ͽ�Ʈ�� �˰���
#include<stdio.h>

#define FALSE 0
#define TRUE 1
#define INF 10000000	// ���Ѵ� ǥ��
const int num = 6;

int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

int v[6]; // �湮�� ���
int d[6]; // �Ÿ�

// ���� �ּ� �Ÿ��� ������ ������ ��ȯ
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
				if (d[current] + a[current][j] < d[j])	// ���̳��� ���α׷����� �����Դϴ�
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