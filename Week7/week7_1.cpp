#include<stdio.h>
#include<math.h>

//학생 정보 출력 함수
void name(void)
{
	printf("=======================\n");
	printf("제\n");
	printf("개인정보는\n");
	printf("비밀입니다\n");
	printf("=======================\n");
}

//제곱해주는 함수 프로토 타입
void repeatPow(int, int);

int main(void)
{
	name();


	//입력받을 밑수와 지수 변수
	int x, y;


	//사용자로부터 정보 입력받기
	printf("밑수와 지수를 입력해주세요:");
	scanf("%d %d", &x, &y);


	
	if ((x > 0 && x<=9) && (y > 0 && y<=9))                //밑수와 지수가 1~9사이일 때, 제곱함수 호출
		repeatPow(x, y);
	else                                                   //범위 밖일 경우, 정상범위가 입력될 때까지 사용자에게 반복 요청
	{
		do
		{
			printf("밑수와 지수를 입력해주세요:");
			scanf("%d %d", &x, &y);
		} while ((x <= 0 || x > 9) || (y <= 0 || y > 9));  //정상 범위 입력 될 경우 반복문 빠져나와서
		repeatPow(x, y);                                   //제곱 함수 호출
	
	}
}


//제곱 함수 정의

void repeatPow(int a, int b)
{

	//반복문에서 사용할 변수
	int i;

	printf("< 결 과 >\n");
	for (i = 1; i <= b; i++)                         //제곱 과정 출력
	{
		printf("%d ^ %d = %.0lf\n", a, i, pow(a,i)); //pow함수의 반환값이 double이므로 정수 부분만 출력되게 %.0lf
	}
}