#include<stdio.h>

// ���丮�� �Լ��� ���� �Լ��� ����
int Factorial(int num) {
	if (num <= 1) return(1); // ��ȯ�� ���ߴ� �κ�!(������ ���ѷ����� ���� �����߻��մϴ�.)
	else return (num * Factorial(num - 1));
}

int main() {
	int i;
	// 1���� 10���� ���丮�� ���� ���
	for (i = 1; i <= 10; i++) {
		printf("%2d! = %d\n", i, Factorial(i));
	}
	return 0;
}