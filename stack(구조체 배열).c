#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100
// 구조체를 정의하여 스택에 넣고 뺄겁니다.
typedef struct {
	int nBirthday;			// 생년월일
	char name[MAX_STRING];	// 이름
	char team[MAX_STRING];	// 소속팀
} element;

element stack[MAX_STACK_SIZE];
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

int main(void) {
	element inputelement = { 920708,
				   "SonHeungMin",
				   "Tottenham Hotspur" };
	element outputelement;
	
	push(inputelement);
	outputelement = pop();		// 스택에 넣었던 구조체를 빼서 outputelement에 대입하여 이를 바탕으로 출력하겠습니다.

	printf("생년월일: %d\n", outputelement.nBirthday);
	printf("이름: %s\n", outputelement.name);
	printf("소속팀: %s\n", outputelement.team);
}