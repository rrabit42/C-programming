#include <stdio.h>
#define SIZE 20                         //상수는 20으로 정의

//함수들의 프로토타입(각 함수 설명은 정의 주석에서)
void input(int[], int);
void output(int[], int);
int sum(int [], int);
void average(int, int, float *);
void maxmin(int[], int, int*, int*);


//학생 정보 출력 함수
void NAME(void)
{
	printf("=========================\n");
	printf("=========================\n");
}


//메인 함수(학생수 입력받기, 각 함수 호출하기, 결과 출력하기)
int main(void)
{
	NAME(); //학생 정보 출력


	//변수 지정
	int score[SIZE];                  //학생 점수 받을 1차원 정수 배열
	int total, maxValue, minValue;    //점수 합계, 최댓값, 최솟값 받을 변수
	float avg;                        //평균 받을 변수
	int realNum;                      //학생 수 받을 변수


	//학생 수 입력받기
	do {
		printf("점수 입력 받을 학생 수는?<1~20>:");
		scanf("%d", &realNum);
	} while (realNum < 1 || realNum>20);      //1~20범위가 아닌 경우 재입력받기



	printf("\n");  //한줄 띄우기


	input(score, realNum);                         //학생 점수 배열에 입력받기
	printf("\n++++++++ 결  과 ++++++++\n");        //결과 출력
	output(score, realNum);                        //각 학생 점수 출력
	total = sum(score, realNum);                   //total 변수에 점수 총합 반환받기
	printf("합계:%d\n", total);                    //합계 출력
	average(realNum, total, &avg);                 //avg 변수에 평균 받기
	printf("평균:%.2f\n",avg);                     //평균 출력
	maxmin(score, realNum, &maxValue, &minValue);  //maxValue, minValue에 각각 최댓값, 최솟값 받기
	printf("최대:%d\n",maxValue);                  //최댓값 출력
	printf("최소:%d\n",minValue);                  //최솟값 출력

}

//학생 점수 입력받는 함수
void input(int score[], int realNum)
{
	for (int i = 0; i < realNum; i++)               //반복문 이용하여 입력받은 학생 수 만큼
	{
		printf("학생%d:", i + 1);                   //빈 배열에 점수를 입력 받는다
		scanf("%d", &score[i]);
		if (score[i] < 0 || score[i]>100)           //점수가 정상범위(0~100)이 아닐 시
		{
			do {
				printf("다시 입력해주세요.\n");     //정상범위 입력 때까지 다시 입력 받기
				printf("학생%d:", i + 1);
				scanf("%d", &score[i]);
			} while (score[i] < 0 || score[i]>100);
		}
	}
}


//각 학생 점수 출력 함수
void output(int score[], int realNum)
{
	printf("학생 점수:");
	for (int i = 0; i < realNum; i++)        //배열에 저장한 학생 점수들을 학생 수 만큼 출력한다
	{
		printf("%d  ", score[i]);
	}
	printf("\n");                            //출력 끝났으면 줄바꾸기

}


//점수들의 총합 반환 함수
int sum(int score[], int realNum)
{
	int total = 0;                           //총합 변수 초기화
	for (int i = 0;i < realNum;i++)          //점수들의 합계를 구한다
	{
		total += score[i];
	}

	return total;                            //합계 반환
}


//avg에 평균값 입력 함수
void average(int realNum, int total , float *avg)
{
	float average;                             //평균 받을 변수 초기화
	average = total / float(realNum);          //float 형식에 맞게 평균 계산해서 대입
	*avg = average;                            //avg에 평균값 대입

}


//최솟값, 최댓값 입력 함수
void maxmin(int score[], int realNum, int*maxValue, int*minValue)
{
	int max = score[0], min = score[0];        //최댓값, 최솟값 변수의 초기값을 배열의 한 정수로 초기화

	for (int i = 0;i < realNum;i++)            //배열의 모든 점수들과 비교해
	{
		if (max < score[i])                    //최댓값 찾아서 max에 대입
			max = score[i];

		if (min > score[i])                    //최솟값 찾아서 min에 대입
			min = score[i];
	}
	*maxValue = max;                           //maxValue에 찾은 최댓값 대입
	*minValue = min;                           //minValue에 찾은 최솟값 대입
}