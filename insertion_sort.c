// 삽입 정렬
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void insertion_sort(int list[], int n) {
	int i, j, key;
	for (i = 0; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];	// 레코드의 오른쪽 이동
		list[j + 1] = key;
	}
}

int main(void) {
	int i, x;
	n = MAX_SIZE;
	printf("10개의 정수를 입력하세요 \n");
	for (i = 0; i < MAX_SIZE; i++) {
		scanf_s("%d", &x);
		list[i] = x;
	}
	insertion_sort(list, n);	// 삽입 정렬 호출
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}