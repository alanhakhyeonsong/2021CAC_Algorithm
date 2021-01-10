#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element* data;	// data는 포인터로 정의합니다.
	int capacity;	// 현재 크기
	int top;
} StackType;

// 스택 생성 함수
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));	// 동적 할당
}
// 공백 상태 검사
int is_empty(StackType* s) {
	return (s->top == -1);
}
// 포화 상태 검사
int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}
// 삽입 연산
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;	// 스택의 크기를 두배로 늘려줍니다.
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element)); // realloc 함수로 재할당 합니다. 
	}
	s->data[++(s->top)] = item; // 스택의 top 값을 증가 시킨 뒤 요소를 삽입
}
// 삭제 연산
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--]; // 현재 스택의 top에 위치한 요소를 호출 한 뒤 top 값은 감소(후위 연산을 쓰는 이유)
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