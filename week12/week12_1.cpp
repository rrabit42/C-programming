#include <stdio.h>

//학생 정보 매크로 상수로 지정
#define NAME "====================\n"\
"====================\n"

int myPow(int, int);  //정수 두개를 입력하면 제곱을 수행할 함수의 프로토타입
int main(void)        //메인함수
{
	//학생 정보 출력
	printf(NAME);
	
	//변수 지정
	int a, b, res;  //차례로 입력받을 정수 두개, myPow함수로부터 반환값 돌려받을 변수

	//0이상의 값이 아닐 경우 정수 다시 입력받기
	do {
		printf("0 이상의 정수 두 개를 입력하세요\n");
		scanf("%d%d", &a, &b);
	} while (a < 0 || b < 0);

	//0이상의 정수일 경우 myPow함수로부터 결과값 돌려받기
	res = myPow(a, b);

	//결과 출력
	printf("%d의 %d승은 %d입니다\n", a, b, res);
}


//제곱을 계산해주는 함수
int myPow(int a, int b)  //0이상의 정수 두개를 입력받는다
{
	if (a == 0)          //밑이 0일경우
		return 0;        //값은 0이다
	else if (b == 0)     //지수가 0일 경우
		return 1;        //값은 1이다
	else                 //밑, 지수 모두 0이 아닌 경우
		return a * myPow(a, b - 1);    //재귀함수를 이용하여 값 반환하기
}