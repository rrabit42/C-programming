#include<stdio.h>      //기본함수 헤더파일
#include<stdlib.h>     //동적할당 위한 헤더 파일

//학생정보 출력 매크로
#define NAME printf("=========================\n");\
printf("=========================\n")

//배열에 저장된 숫자들의 평균 계산하는 함수의 프로토타입
float func(int *, int num);

int main(void)
{
	//학생정보 출력
	NAME;

	//변수들
	int num;           //그룹인원 수
	int *arr = NULL;   //동적메모리 가리킬 포인터 및 초기화

	//0 입력시까지 반복하기
	while (1)
	{
		//사용자에게 그룹인원 입력받기
		num = printf("\n그룹인원은 몇명입니까?<0~100>\n");
		scanf("%d", &num);

		//범위(0~100)에서 벗어난 값이면 다시 입력받기
		if (num < 0 || num>100)
		{
			printf("인원은 0에서 100까지입니다.\n");
			continue;
		}
		else if (num == 0) break; //입력받은 값이 0이면 반복문 탈출

		//그룹인원 수 만큼 동적 메모리 할당하기
		arr = (int*)malloc(sizeof(int)*num);

		//만약 포인터 값이 null이면,
		if (arr == NULL)
		{
			printf("동적 메모리 할당 실패\n");
			return -1;                         //동적 메모리 할당 실패한 것이므로 비정상 프로그램 ㅈ오료
		}

		//포인터 값이 정상이면, 그룹멤버들의 나이를 메모리배열에 저장하기
		printf("그룹멤버의 나이를 입력하세요<0~120>\n");
		for (int i = 0; i < num; i++)                       //멤버 수 만큼 나이 입력받기
		{
			scanf("%d", &arr[i]);
			while (arr[i] < 0 || arr[i]>100)                //나이가 범위에서 벗어난 값이면
			{
				printf("나이는 0에서 120 사이입니다.\n");   //정상 범위 안내해 주고,
				scanf("%d", &arr[i]);                       //정상 범위 입력시까지 다시 입력받기
			}
		}

		//프로그램 결과 출력
		printf("그룹멤버의 평균 나이는 %.2f입니다\n", func(arr, num)); //그룹멤버 평균 나이를 함수 호출해서 출력

		free(arr);   //평균 구했으면 할당했던 메모리 해제
		arr = NULL;  //NULL을 대입해 준다
	}

	//반복문 끝나면 프로그램 정상 종료한다
	printf("프로그램을 종료합니다.\n");
	return 0;
}

//그룹멤버의 평균 나이 구하는 함수
float func(int *arr, int num)       //인자로는 포인터와 그룹 인원 수 받기
{
	int sum = 0;                    //합계 변수
	for (int i = 0; i < num; i++)   //그룹 인원 수 만큼 반복해서
	{
		sum += arr[i];              //나이 합계 구하기
	}
	return float(sum) / float(num); //그룹의 평균 나이 반환
}