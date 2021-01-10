#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

// ���� ť
typedef int element;
typedef struct {
	int front;	// ť�� ����
	int rear;	// ť�� �Ĵ�
	element data[MAX_QUEUE_SIZE];
} QueueType;

// ���� ����
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// �ʱ�ȭ
void init_queue(QueueType* q) {
	q->rear = -1;
	q->front = -1;
}
// ť ��� �Լ�
void queue_print(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf(" | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}
// ��ȭ ���� �˻�
int is_full(QueueType* q) {
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}
// ���� ���� �˻�
int is_empty(QueueType* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}
// ����
void enqueue(QueueType* q, int item) {
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->data[++(q->rear)] = item;	// rear���� ���� �� ��� ����(���������ڸ� ����ϴ� ����)
}
// ����
int dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.");
		return -1;
	}
	int item = q->data[++(q->front)];	// front���� ���� �� ��� ����
	return item;
}

int main(void) {
	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	return 0;
}