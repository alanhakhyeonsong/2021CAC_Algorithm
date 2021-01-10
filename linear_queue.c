#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

// 선형 큐
typedef int element;
typedef struct {
	int front;	// 큐의 전단
	int rear;	// 큐의 후단
	element data[MAX_QUEUE_SIZE];
} QueueType;

// 오류 검출
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 초기화
void init_queue(QueueType* q) {
	q->rear = -1;
	q->front = -1;
}
// 큐 출력 함수
void queue_print(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf(" | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}
// 포화 상태 검사
int is_full(QueueType* q) {
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}
// 공백 상태 검사
int is_empty(QueueType* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}
// 삽입
void enqueue(QueueType* q, int item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;	// rear값을 증가 후 요소 삽입(전위연산자를 사용하는 이유)
}
// 삭제
int dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];	// front값을 증가 후 요소 삭제
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