#include<stdio.h>
#define NUM 10                                 //NUM은 10으로 정의

void name(void)                                //학생 정보 출력 함수 정의
{
	printf("=======================\n");
	printf("=======================\n");
}

int main(void)
{
	name();                                    //학생 정보 출력



	//학생 수 입력받기

	int num;                                      //학생 수 입력받을 변수

	do {
		printf("학생수는 몇명인가요?(1~10)\n");
		scanf("%d", &num);
	} while (num < 1 || num > 10);               //1~10 양수만 가능, 그 외 숫자 입력시 올바른 범위 수 입력 받을 때까지 반복






	//학생들의 점수 입력 받기

	printf("학생 수 %d명의 점수를 입력하세요(0~100)\n", num);

	int score[NUM];  //점수 입력 받을 숫자열

	for (int i = 0; i < num; i++) //학생 수 만큼 각각 점수 입력 받기
	{
		printf("학생%d: ", i + 1);
		scanf("%d", &score[i]);

		while (score[i] < 0 || score[i] > 100)       //만약 점수가 0~100의 정수가 아니라면
		{
			printf("다시 입력해주세요(0~100)\n");
			printf("학생%d: ", i + 1);
			scanf("%d", &score[i]);                  //올바른 범위의 값 입력 시 까지 반복
		}
	}




	// 각 학생의 점수 출력하기

	printf("\n<각 학생의 점수>\n");
	for (int i = 0; i < num; i++)
	{
		printf("학생%d: %d\n", i + 1, score[i]);
	}


	printf("=======================\n");


	//학생들 점수의 합계, 평균, 최대값, 최소값 계산

	int sum=0;                        //합계 변수 및 초기화
	float average;                    //평균 변수
	int max, min;                     //최대값, 최소값 변수

	for (int i = 0; i < num; i++)     //점수들의 합계 구하기
		sum += score[i];

	average = float(sum) / num;       //평균 계산하기

	max = score[0];                   //최대값 초기화(숫자열의 첫째 수로)
	min = score[0];                   //최소값 초기화(숫자열의 첫째 수로)


	//최대값, 최소값 찾기


	for (int i = 0; i < num; i++)
	{
		if (max < score[i])     //숫자열의 수 중 max보다 큰 수가 나타나면
			max = score[i];     //그 수가 max가 된다

		if (min > score[i])     //숫자열의 수 중 min보다 작은 수가 나타나면
			min = score[i];     //그 수가 min이 된다
	}


	////학생들 점수의 합계, 평균, 최대값, 최소값 출력

	printf("합계: %d\n", sum);
	printf("평균: %.2f\n", average);
	printf("최대: %d\n", max);
	printf("최소: %d\n", min);


}