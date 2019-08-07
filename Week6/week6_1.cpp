#include <stdio.h>
int main(void)
{
	//사용자에게서 정수 입력 요구
	printf("1~10 사이의 정수를 입력하세요:\n");
	
	//변수 지정 및 초기화
	int num;         // 입력받을 변수
	int sum=1 ;      // factorial 계산 합을 위한 변수 및 초기화
	int i;           // for문을 위한 변수 지정

	//사용자에게서 정수 입력 받기
	scanf("%d", &num);

	//factorial 계산

	if (num >= 1 && num <= 10)                      //num이 1~10사이 정수일 경우
	{
		for (i = 1; i <= num; i++)                  //factorial계산
		{
			sum *= i;
			printf("%d! = %d\n", i, sum);           //계산 과정 보여주기
		}
		printf("\n%d!의 값은 %d입니다\n", num, sum);//결과 값 출력
	}

	else                                           //그 외의 정수일 경우
		printf("범위 밖의 수입니다.");

}