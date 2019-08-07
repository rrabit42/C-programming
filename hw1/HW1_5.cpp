#include<stdio.h>
void name(void)
{
	printf("=======================\n");
	printf("=======================\n");
}

//함수 프로토 타입
double add(double x, double y);              //덧셈 함수
double substraction(double x, double y);     //뺄셈 함수
double multiplication(double x, double y);   //곱셈 함수
double division(double x, double y);         //나눗셈 함수

int main(void)
{
	name();

	//입력받을 수식의 변수 정의
	double x;  //숫자1
	char cal;  //수식 기호
	double y;  //숫자2


	//계산할 수식 입력 받기
	printf("<계산기>\n");
	printf("수식:");
	scanf("%lf%c%lf", &x, &cal, &y);


	switch (cal) //cal의 기호에 따라 호출하는 함수가 다름

		//소숫점 둘째자리까지만 출력(실행 예시 참고)
	{
	case '+': printf("%.2lf %c %.2lf = %.2lf", x, cal, y, add(x, y)); break;               //'+'기호 입력받으면 덧셈 함수 호출
	case '-': printf("%.2lf %c %.2lf = %.2lf", x, cal, y, substraction(x, y)); break;      //'-'기호는 뺄셈 함수 호출
	case '*': printf("%.2lf %c %.2lf = %.2lf", x, cal, y, multiplication(x, y)); break;    //'*'기호는 곱셈 함수
	case '/': printf("%.2lf %c %.2lf = %.2lf", x, cal, y, division(x, y)); break;          //'/'기호는 나눗셈 함수
	default: printf("잘못 입력하셨습니다\n");                                              //나머지 문자 입력 시

	}


}


double add(double x, double y)           //덧셈 함수 정의
{
	double result;                       //결과 값 초기화
	result = x + y;                      //수식 계산
	return result;                       //결과값 반환
}

double substraction(double x, double y)  //뺄셈 함수 정의
{
	double result;                       //이하 동문
	result = x - y;
	return result;
}

double multiplication(double x, double y)//곱셈 함수 정의
{
	double result;                       //이하 동문
	result = x * y;
	return result;
}

double division(double x, double y)      //뺄셈 함수 정의
{
	double result;                       //이하 동문
	result = x - y;
	return result;
}