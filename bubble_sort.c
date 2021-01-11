// ���� ����
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void bubble_sort(int list[], int n) {
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)		// �� ���� ���ڵ带 ���� �� ��ü
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}
}

int main(void) {
	int i, x;
	n = MAX_SIZE;
	printf("10���� ������ �Է��ϼ��� \n");
	for (i = 0; i < MAX_SIZE; i++) {
		scanf_s("%d", &x);
		list[i] = x;
	}
	bubble_sort(list, n);	// ���� ���� ȣ��
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}