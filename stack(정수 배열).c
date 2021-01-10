#include<stdio.h>
#include<stdlib.h>

// 스택을 전역변수로 셋팅 및 각 연산 함수들은 전역 함수로 셋팅 후 main 함수에서 실행합니다.

#define MAX_STACK_SIZE 100	// 스택의 최대 크기 설정
typedef int element;			// 데이터의 자료형
element stack[MAX_STACK_SIZE];  // 1차원 배열(int형 스택)
int top = -1;

// 공백 상태 검사
int is_empty() {
	return (top == -1); // 스택의 top이 -1 이면 공백 상태
}
// 포화 상태 검사
int is_full() {
	return (top == (MAX_STACK_SIZE - 1)); // 스택의 top이 (최대크기 - 1) 이면 포화 상태 
}
// 삽입 연산
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n"); // fprintf 함수로 에러 출력
		return;
	}
	else stack[++top] = item; // 스택의 top을 증가 시킨 뒤 요소를 삽입
}
// 삭제 연산
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--]; // 현재 스택의 top에 위치한 요소를 호출 한 뒤 top 값은 감소
}
// 피크 함수: 현재 스택의 top에 위치한 요소를 삭제 없이 호출만 하는 함수입니다.
element peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top];
}

int main(void) {	// 순서대로 push 후 pop을 시키면 어떤 순서로 호출되는지에 주목하세요.
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}