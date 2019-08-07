#include <stdio.h>
#include <stdlib.h>  //random함수들 헤더 파일
#include <time.h>    //time함수들 헤더 파일


//학생 정보 출력 함수
void NAME()
{
	printf("===================\n");
	printf("===================\n");
}

int main()
{
	//학생 정보 출력
	NAME();
	
	//변수
	double num;                       //카드 뽑는 횟수 변수
	int what;                         //랜덤값 받을 변수
	int D = 0, S = 0, H = 0, C = 0;   //차례로 다이아몬드, 스페이드, 하트, 클로버가 나온 횟수 변수

	//카드 뽑기
	do{
		//사용자에게 카드 뽑을 횟수를 입력 받는다
		printf("\n카드를 뽑는 횟수(1~100000000, 종료시 0 입력>: ");
		scanf("%lf", &num);

		//잘못된 범위 입력시
		if (num < 0 || num>100000000)
		{
			printf("잘못된범위\n");
			continue;                  //횟수 다시 물어본다
		}
		//0 입력시
		else if (num == 0)
			break;                     //즉시 카드 뽑기 종료
		
		//정상범위 입력 시
		srand(time(NULL));             //seednumber를 1초마다 바꿔서 반복 실행시 마다 결과가 변하도록
		for (int i = 0; i < num;i++)   //사용자가 입력한 횟수 만큼 카드를 랜덤하게 뽑는다
		{
			what = rand() % 4;         //0~3까지 숫자 랜덤하게 뽑기
			switch (what) {            //만약 what이
			case 0: D += 1; break;     //0이면 다이아몬드
			case 1: S += 1; break;     //1이면 스페이드
			case 2: H += 1; break;     //2  면 하트
			case 3: C += 1; break;     //3이면 클로버이다. 카드 뽑았으므로 숫자에 맞는 카드 횟수 +1
			}
		}
		
		//결과 출력
		printf(" - Diamond:\t%d회, 비율:%.2f%%\n",D,(D/float(num))*100);  //다이아몬드가 나온 횟수와 비율(백분율)
		printf(" - Spade:\t%d회, 비율:%.2f%%\n",S,(S/float(num))*100);    //스페이드
		printf(" - Heart:\t%d회, 비율:%.2f%%\n",H,(H/float(num))*100);    //하트
		printf(" - Clover:\t%d회, 비율:%.2f%%\n",C,(C/float(num))*100);   //클로버

	} while (num != 0); //0을 입력하기 전까지 반복한다


	//0을 입력했으면 프로그램을 종료한다
	printf("프로그램 종료\n");
}