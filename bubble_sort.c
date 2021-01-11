// 버블 정렬
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void bubble_sort(int list[], int n) {
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)		// 앞 뒤의 레코드를 비교한 후 교체
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
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
	bubble_sort(list, n);	// 버블 정렬 호출
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}