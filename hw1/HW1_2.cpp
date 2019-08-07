#include <stdio.h>
void name(void)
{
	printf("=======================\n");
	printf("=======================\n");
}

int main(void)
{

	name();

	//변수 지정
	int num;                                      //사용자에게 입력 받을 정수
	int i,j,k;                                    //반복문에 쓰일 변수


	//사용자에게 값을 입력받는다
	printf("Enter the height of the triangle:");
	scanf("%d", &num);


	//피라미드모양 만들기
	if (num >= 1 && num <= 20)                    //정수는 1~20 사이어야 한다.
	{
		for (i = 1;i <= num; i++)
		{
			for (k = 1;k <=(num - i);k++)         //*가 가운데정렬 되도록 space 띄우기
				printf(" ");
			for (j = 1; j <= (i * 2 - 1); j++)    //* 출력(*는 홀수개)
					printf("*");
			printf("\n");                         //한 줄 출력 끝나면 줄바꿈
		}
	}

	else                                          //범위 밖의 값일 경우
		printf("잘못된 입력입니다\n");

}