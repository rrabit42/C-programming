#include <stdio.h>

#define ROW 5        //행 상수 지정
#define COLUMN 7     //열 상수 지정


//학생 정보 출력 함수
void NAME()
{
	printf("===================\n");
	printf("===================\n");
}

//좌석 보여주는 함수의 프로토타입
void viewSeats(int [][COLUMN]);

int main()
{
	NAME();                 //학생 정보 출력

	int seat[ROW][COLUMN];  //좌석 배열
	int row, column;        //입력받을 행, 열 변수
	

	//배열을 0으로 초기화
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
			seat[i][j] = 0;
	}


	//좌석 예약하기
	while (1){
		viewSeats(seat);                     //사용가능한 좌석 보여주기
		printf("빈 좌석을 선택해주세요.(빈 좌석-0/예약된 좌석-1/종료 9 9 입력)");
		scanf("%d %d", &row, &column);       //사용자로부터 좌석 입력 받기
		if (row == 9 && column == 9) break;  //9 9입력시 종료
		seat[row][column] = 1;               //9 9아닌 좌석 입력시 좌석 예약해주기

	}
}


//좌석 보여주는 함수
void viewSeats(int seat[][COLUMN])            //2차원 배열을 인자로 받는다
{
	printf("\n행/열| 0\t1\t2\t3\t4\t5\t6\t");  //좌석표 출력하기
	printf("\n------------------------------------------------------------------\n");
		for (int i = 0; i < ROW; i++){
			printf("    %d| %d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",i,seat[i][0],seat[i][1],seat[i][2],seat[i][3],seat[i][4],seat[i][5],seat[i][6]);
	}
}
