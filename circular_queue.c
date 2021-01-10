#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// ���� ����
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// �ʱ�ȭ
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}
// ���� ���� �˻�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
// ��ȭ ���� �˻�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// ���� ť ���
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
// ���� ����
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("��ȭ ���� �Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// ���� ����
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("���� ���� �Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
// ���� ����
element peek(QueueType* q) {
	if (is_empty(q))
		error("���� ���� �Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&queue)) {
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("��ȭ ���� �Դϴ�.\n\n");

	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("������ ����: %d \n", element);
		queue_print(&queue);
	}
	printf("���� ���� �Դϴ�.\n");
	return 0;
}