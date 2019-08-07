#include <stdio.h>
#include <stdlib.h> //random관련 함수 포함하는 헤더파일
#include <time.h>   //time관련 함수 포함하는 헤더파일

//학생정보 매크로 상수로 지정
#define NAME "====================\n"\
"====================\n"

int main(void)
{
	//학생 정보 출력하기
	printf(NAME);

	//사용될 변수 지정하기
	int num;              //사용자로부터 입력받을 정수
	char ans;             //사용자로부터 입력받을 문자
	int yeah[15];         //정답 배열

	srand(time(NULL));    //seed값을 코드 실행시마다 바꾼다

	for (int i = 0; i < 15; i++)   //yeah 배열에 랜덤으로 0 혹은 1을 넣는다
	{
		yeah[i] = rand() % 2;
	}


	//뽑기표 출력
	printf("<뽑기>\n");
	for (int i = 0; i < 15; i++)              //0~14의 뽑기를 뽑을 수 있다.
	{
		printf("[%2d] ", i);
		if ((i + 1) % 5 == 0) printf("\n");   //한 줄에 5개씩 출력되도록
	}


	//사용자가 문자 y를 입력하면 뽑기 반복
	do {

		//번호 입력받기
		printf("번호를 선택하세요<0~14>: ");
		scanf("%d", &num);

		  //번호가 범위 밖의 값일 경우
		while (num < 0 || num >14)
		{
			printf("범위밖의 값입니다.\n");
			printf("계속하시겠습니까?<y/n>:");
			scanf(" %c", &ans);                   //계속할건지 여부 입력 받기
			printf("\n");
			if (ans != 'y') break;                //y가 아니면 while문 탈출
			printf("번호를 선택하세요<0~14>: ");  //y일 경우 뽑기 반복
			scanf("%d", &num);
		}

		   //번호가 범위 안의 값일 경우
		while (num >= 0 && num <= 14)
		{

			   //뽑은 뽑기가 1일 경우는 당첨!
			if (yeah[num] == 1)
			{
				printf("당첨!\n");
				printf("계속하시겠습니까?<y/n>:");   //계속할건지 여부 입력 받기
				scanf(" %c", &ans);
				printf("\n");
				if (ans != 'y') break;               //y가 아니면 while문 탈출
				printf("번호를 선택하세요<0~14>: ");
				scanf("%d", &num);
			}
			   //뽑은 뽑기가 0일 경우는 꽝!
			else
			{
				printf("꽝! 다음 기회에...\n");
				printf("계속하시겠습니까?<y/n>:");
				scanf(" %c", &ans);                  //계속할건지 여부 입력받기
				printf("\n");
				if (ans != 'y') break;
				printf("번호를 선택하세요<0~14>: ");
				scanf("%d", &num);
			}
		}

		//do while 내 모든 반복문 탈출

	} while (ans == 'y');  //그때 ans가 y가 아니면 뽑기 종료하고 정답을 출력한다


	//정답
	printf("<정답>\n\n");
	for (int i = 0; i < 15; i++)
	{
		printf("[%2d] ", yeah[i]);
		if ((i + 1) % 5 == 0) printf("\n"); //정답 배열을 한줄에 5개씩 출력한다
	}

}