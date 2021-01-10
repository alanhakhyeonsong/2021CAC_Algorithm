#include<stdio.h>
#include<stdlib.h>

// ������ ���������� ���� �� �� ���� �Լ����� ���� �Լ��� ���� �� main �Լ����� �����մϴ�.

#define MAX_STACK_SIZE 100	// ������ �ִ� ũ�� ����
typedef int element;			// �������� �ڷ���
element stack[MAX_STACK_SIZE];  // 1���� �迭(int�� ����)
int top = -1;

// ���� ���� �˻�
int is_empty() {
	return (top == -1); // ������ top�� -1 �̸� ���� ����
}
// ��ȭ ���� �˻�
int is_full() {
	return (top == (MAX_STACK_SIZE - 1)); // ������ top�� (�ִ�ũ�� - 1) �̸� ��ȭ ���� 
}
// ���� ����
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n"); // fprintf �Լ��� ���� ���
		return;
	}
	else stack[++top] = item; // ������ top�� ���� ��Ų �� ��Ҹ� ����
}
// ���� ����
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--]; // ���� ������ top�� ��ġ�� ��Ҹ� ȣ�� �� �� top ���� ����
}
// ��ũ �Լ�: ���� ������ top�� ��ġ�� ��Ҹ� ���� ���� ȣ�⸸ �ϴ� �Լ��Դϴ�.
element peek() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}

int main(void) {	// ������� push �� pop�� ��Ű�� � ������ ȣ��Ǵ����� �ָ��ϼ���.
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}