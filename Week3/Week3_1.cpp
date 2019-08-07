#include <stdio.h>

int main(void)
{
	//사용자에게 입력 받을 정수 3개 지정
	int a, b, c;

	//사용자에게 입력 요청하기
	printf("정수 3개를 입력하세요\n");
	scanf("%d%d%d", &a, &b, &c);

	//결과 화면 출력
	printf("\n세 정수:%d,%d,%d\n", a, b, c);

	//합계와 평균을 구하기 위한 변수 지정
	int sum;
	double average;

	//합계와 평균을 구하기 위한 계산
	sum = a + b + c;
	average = (float) (a + b + c) / 3;

	//결과 화면 출력
	printf("세 정수의 합:%d\n", sum);
	printf("세 정수의 곱:%.2f\n", average);
}