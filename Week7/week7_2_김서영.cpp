#include<stdio.h>
#include<math.h>

void name(void)
{
	printf("=======================\n");
	printf("제\n");
	printf("개인정보는\n");
	printf("비밀입니다\n");
	printf("=======================\n");
}

//함수 프로토 타입
int getLength(int, int);               //길이 계산 함수
int getArea(int, int, int, int);       //면적 계산 함수
int getPerimeter(int, int, int, int);  //둘레 계산 함수


int main(void)
{
	name();


	//좌표 변수들
	int x1, y1, x2, y2;


	//사용자로부터 (x1,y1)좌표값 입력 받기
	printf("(x1, y1) 좌표 입력: ");
	scanf("%d %d", &x1, &y1);



	if (x1 >= 0 && y1 >= 0)                         //0이상의 값만 허용 
	{
		                                            //(x1,y1)을 정상적으로 입력 받으면 (x2,y2)입력받기
		printf("(x2, y2) 좌표 입력: ");
		scanf("%d %d", &x2, &y2);
	}
	else                                            //0 미만의 값이 입력되면 정상 범위가 입력될 때까지 반복
	{
		do
		{
			printf("x1,y1은 양수입니다.\n");
			printf("(x1, y1) 좌표 입력: ");
			scanf("%d %d", &x1, &y1);

		} while (x1 < 0 && y1 < 0);


		printf("(x2, y2) 좌표 입력: ");	            //정상 범위 입력되면 (x2,y2) 좌표값 입력 받기
		scanf("%d %d", &x2, &y2);
	}



	
	if (x2 >= 0 && y2 > 0)                           //x2,y2도 0이상의 값만 입력 받는다
	{
		printf("(x1, y1) = (%d, %d), (x2, y2) = (%d, %d)\n", x1, y1, x2, y2); //좌표들 확인
	}
	else
	{
		do
		{
			printf("x2,y2는 양수입니다.\n");         //정상 범위 입력 때까지 다시 입력 받기
			printf("(x2, y2) 좌표 입력: ");
			scanf("%d %d", &x2, &y2);
		} while (x2 < 0 && y2 < 0);

		printf("\n(x1, y1) = (%d, %d), (x2, y2) = (%d, %d)\n", x1, y1, x2, y2); //정상 범위 안에서 입력 끝나면 좌표들 확인
	}


	//함수 호출하여 좌표값들이 이루는 직사각형에 대한 결과값 출력
	printf("직사각형의 너비는 %d입니다.\n",getLength(x1,x2));              //직사각형의 너비
	printf("직사각형의 높이는 %d입니다.\n",getLength(y1,y2));              //직사각형의 높이
	printf("직사각형의 면적는 %d입니다.\n",getArea(x1,x2,y1,y2));          //직사각형의 면적
	printf("직사각형의 둘레는 %d입니다.\n",getPerimeter(x1,x2,y1,y2));     //직사각형의 둘레

}


//길이 계산 정의 함수
int getLength(int a, int b)
{
	int result;           //결과 변수 지정
	result = abs(a - b);  //절대값 함수 사용하여 길이 구하기
	return result;        //결과값 반환
}

//면적 계산 함수 정의(이하 동문)
int getArea(int a, int b, int c, int d)
{
	int area;
	area = abs(a - b)*abs(c - d);
	return area;
}

//둘레 계산 함수 정의(이하 동문)
int getPerimeter(int a, int b, int c, int d)
{
	int length;
	length = 2 * abs(a - b) + 2 * abs(c - d);
	return length;
}

