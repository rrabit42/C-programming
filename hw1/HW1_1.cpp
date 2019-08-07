#include <stdio.h>
void name(void)
{
	printf("=======================\n");
	printf("=======================\n");
}
int main(void)
{
	name();



	//사용자로부터 받을 입력값 안내하기
	printf("사각형의 가로와 세로 길이를 입력: ");

	//가로와 세로 길이 변수 지정
	int base, high;

	//입력 받기
	scanf("%d%d", &base, &high);



	//사각형을 그리기 위한 변수 지정
	int i,j;


	//사각형 그리기
	if ((high >= 2 && high <= 50) && (base >= 2 && base <= 50))   //가로&세로 길이는 각각 2~50 사이
	{
		for (i = 1; i <= base; i++)                               //윗변 만들기    
			printf("*");

		printf("\n");                                             //다음 줄로 넘어가기

		for (j = 1; j <= (high-2); j++)                           //중간 부분 만들기
		{
			printf("*");                                               //처음 *출력(테두리)
			for (i = 1; i <= (base - 2); i++)                          //테두리를 제외한 나머지 빈칸 출력
				printf(" ");
			printf("*");                                               //마지막 *출력(테두리)
			printf("\n");                                              //다음 줄로 넘어가서 반복
		}

		for (i = 1; i <= base; i++)                               //밑변 만들기
			printf("*");
	}


	else                                                          //범위 밖의 입력값인 경우
		printf("잘못된 입력입니다.\n");
}