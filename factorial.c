#include<stdio.h>

// 팩토리얼 함수는 전역 함수로 구현
int Factorial(int num) {
	if (num <= 1) return(1); // 순환을 멈추는 부분!(없으면 무한루프에 빠져 오류발생합니다.)
	else return (num * Factorial(num - 1));
}

int main() {
	int i;
	// 1에서 10까지 팩토리얼 값을 출력
	for (i = 1; i <= 10; i++) {
		printf("%2d! = %d\n", i, Factorial(i));
	}
	return 0;
}