// 선택 정렬
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n) {
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)	// 최소 값 탐색
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
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
	selection_sort(list, n);	// 선택 정렬 호출
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}