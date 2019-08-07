#include <stdio.h>
void name(void)
{
	printf("=======================\n");
	printf("=======================\n");
}

//함수 프로토 타입

void show_menu(void);  //화면에 메뉴 출력
int func_order(int);   //함수로 부터 메뉴번호 전달 받아 각 메뉴 가격 메인함수로 반환 및 주문한 내역 출력
int main(void)         //메뉴 가격 반환받아 반복 끝나면 총 가격 출력

{
	name();

	//변수 지정
	int kim=1500, duk=3000, drink=700; //각 메뉴의 가격
	int choice;                        //사용자로부터 받을 메뉴 번호
	int sum = 0;                       //총 주문 금액 변수 및 초기화
	int money;                         //사용자로부터 받을 돈 변수

	do
	{
		show_menu();                    //메뉴판 출력
		printf("선택: ");               //사용자로부터 메뉴 번호 입력 받기
		scanf("%d", &choice);

		switch (choice)                 //메뉴 번호에 따라 명령 수행
		{
		case 0: case 1: case 2: case 3: sum += func_order(choice); break;    //0~3일 경우 func_order함수 실행 및 총 주문 금액 계산
		default: printf("잘못 입력하셨습니다. 다시 입력해주세요.\n"); break; //0~3 이외의 숫자일 경우

		}


	} while (choice != 0);              //0을 입력받으면 반복 종료


	printf("총 %d원 입니다. 얼마를 내시겠습니까?", sum);     //사용자의 돈 입력받기
	scanf("%d", &money);
	printf("거스름돈은 %d원 입니다.\n", money - sum);        //거스름돈 계산 및 출력

}

void show_menu()                 //메뉴판 출력 정의
{
	printf("===메뉴선택===\n");
	printf("1.김밥   1500\\\n");
	printf("2.떡볶이 3000\\\n");
	printf("3.음료수  700\\\n");
	printf("0.종료\n");
	printf("==============\n");

}

int func_order(int choice)     //함수 정의
{
	int price = 0;                 //반환 할 가격 변수 초기화

	switch (choice)
	{
	case 1: price = 1500; printf("김밥을 주문하셨습니다.\n"); break;   //주문번호 1일 경우, 변수 초기화 및주문 내역 출력
	case 2: price = 3000; printf("떡볶이를 주문하셨습니다.\n"); break; //주문번호 2일 경우, 변수 초기화 및 주문 내역 출력
	case 3: price = 700; printf("음료수를 주문하셨습니다.\n"); break;  //주문번호 3일 경우, 변수 초기화 및 주문 내역 출력
	case 0:                                                             //주문번호 0일 경우, 반복 빠져나오기
		break;
	}

	return price;                                                      //변수 초기화 한 값(각 메뉴의 가격) 돌려주기

}