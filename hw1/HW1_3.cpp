#include <stdio.h>
#include <math.h>
void name(void)
{
	printf("=======================\n");
	printf("=======================\n");
}

int main(void)
{

	name();


	//변수 지정
	int a, b, c;           //입력받을 방정식의 계수 변수
	double D;              //판별식
	double x1, x2;         //이차 방정식의 근
	int num;               //근의 개수


	//사용자로부터 이차방정식의 계수 입력받기
	printf("이차 방정식: ax^2 + bx + c = 0\n");
	printf("2차방정식의 계수 a,b,c를 입력하세요: ");
	scanf("%d%d%d", &a, &b, &c);



	//판별식 정의
	D = (b*b) - (4*a*c);



	//근의 개수 구하기
	if (D > 0)                             //판별식 D>0 이면 근이 2개
	{
		num = 2;
		x1 = (-b + sqrt(D)) / (a * 2);     //근의 값 2개 각각 구하기
		x2 = (-b - sqrt(D)) / (a * 2);
	}
	else if (D == 0)                       //판별식 D==0이면 근이 1개
	{
		num = 1;
		x1 = -b / (a * 2);                 //근의 값 1개 구하기(D=0이므로 루트D 부분 생략한 공식)
	}
	else
		num = 0;                           //판별식 D<0이면 근이 없다.



	//근 개수에 따라 결과값 출력
	     //근의 값은 소수점 둘째자리 까지 출력한다
	switch (num)
	{
	case 2:
		printf("근이 2개 존재: %1.2lf / %1.2lf\n", x1, x2);
		break;
	case 1:
		printf("근이 1개 존재: %1.2lf\n", x1);
		break;
	default:
		printf("근이 존재하지 않습니다.\n");
	}

	}
