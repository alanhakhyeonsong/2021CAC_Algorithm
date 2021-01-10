#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100
// ����ü�� �����Ͽ� ���ÿ� �ְ� ���̴ϴ�.
typedef struct {
	int nBirthday;			// �������
	char name[MAX_STRING];	// �̸�
	char team[MAX_STRING];	// �Ҽ���
} element;

element stack[MAX_STACK_SIZE];
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

int main(void) {
	element inputelement = { 920708,
				   "SonHeungMin",
				   "Tottenham Hotspur" };
	element outputelement;
	
	push(inputelement);
	outputelement = pop();		// ���ÿ� �־��� ����ü�� ���� outputelement�� �����Ͽ� �̸� �������� ����ϰڽ��ϴ�.

	printf("�������: %d\n", outputelement.nBirthday);
	printf("�̸�: %s\n", outputelement.name);
	printf("�Ҽ���: %s\n", outputelement.team);
}