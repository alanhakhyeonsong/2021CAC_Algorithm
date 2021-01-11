//�÷��̵�-�ͼ� �˰���
#include<stdio.h>

#define INF 10000000	// ���Ѵ� ǥ��
const int num = 4;

// �迭 �ʱ�ȭ
int a[4][4] = {
	{0, 2, INF, 7},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall() {
	// ��� �׷��� �ʱ�ȭ
	int result[4][4];

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			result[i][j] = a[i][j];
	}

	// k = ���İ��� ���
	for (int k = 0; k < num; k++) {
		// i = ��� ���
		for (int i = 0; i < num; i++) {
			// j = ���� ���
			for (int j = 0; j < num; j++) {
				if (result[i][k] + result[k][j] < result[i][j])	// ���̳��� ���α׷����� �����Դϴ�
					result[i][j] = result[i][k] + result[k][j];	// k�� ���İ��ٴ� ���� ǥ��
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