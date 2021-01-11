// 힙 정렬
#include<stdio.h>
#include<stdlib.h>

#define parent(x) (x-1)/2

void heap(int* data, int num) {
	for (int i = 1; i < num; i++) {
		int child = i;
		while (child > 0) {
			int root = parent(child);
			if (data[root] < data[child]) {
				int temp = data[root];
				data[root] = data[child];
				data[child] = temp;
			}
			child = root;
		}
	}
}

int main(void) {
	int num = 9;
	int data[] = { 15, 5, 8, 11, 2, 4, 33, 12, 24 };
	heap(data, num); // 힙 생성

	for (int i = num - 1; i >= 0; i--) {
		// 가장 큰 수(root)를 맨 마지막 원소와 swap
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;

		// 맨 마지막 원소(가장 큰 수)를 제외하고 다시 힙 생성
		heap(data, i);
	}

	for (int i = 0; i < num; i++)
		printf("%d ", data[i]);

	return 0;
}