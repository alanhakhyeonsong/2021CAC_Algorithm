#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element* data;	// data�� �����ͷ� �����մϴ�.
	int capacity;	// ���� ũ��
	int top;
} StackType;

// ���� ���� �Լ�
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));	// ���� �Ҵ�
}
// ���� ���� �˻�
int is_empty(StackType* s) {
	return (s->top == -1);
}
// ��ȭ ���� �˻�
int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}
// ���� ����
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;	// ������ ũ�⸦ �ι�� �÷��ݴϴ�.
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element)); // realloc �Լ��� ���Ҵ� �մϴ�. 
	}
	s->data[++(s->top)] = item; // ������ top ���� ���� ��Ų �� ��Ҹ� ����
}
// ���� ����
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--]; // ���� ������ top�� ��ġ�� ��Ҹ� ȣ�� �� �� top ���� ����(���� ������ ���� ����)
}

int main(void) {
	StackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	free(s.data);
	return 0;
}