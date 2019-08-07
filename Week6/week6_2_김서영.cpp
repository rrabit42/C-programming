#include <stdio.h>
int main(void)
{
	//가격 합산을 위해 금액 변수 및 초기화;
	int ham = 4000, cola = 2000, chi = 3000;

	//메뉴판 출력
	printf("===== 메뉴 =====\n");
	printf("1. 햄버거: %d원\n", ham);
	printf("2. 콜라: %d원\n", cola);
	printf("3. 치킨: %d원\n", chi);
	printf("================\n");
	printf("메뉴를 선택하세요(주문 완료시 0 입력)\n");
	
	//주문 받을 변수
	int order;

	//가격 합산을 위한 변수
	int sum = 0;

	//사용자로부터 주문 받기
	scanf("%d", &order);

	//0을 입력할 경우는 결과를 출력함
	while (order != 0)
	{

		//입력받은 주문 번호에 따라 주문한 음식 이름 출력 및 가격 계산

		switch (order)
		{
		case 1: printf("햄버거를 주문하셨습니다.\n"); sum += ham; break;  // 1. 햄버거 주문 시
		case 2: printf("콜라를 주문하셨습니다.\n"); sum += cola; break;   // 2. 콜라 주문 시
		case 3: printf("치킨을 주문하셨습니다.\n"); sum += chi; break;    // 3. 치킨 주문 시
		default: printf("잘못된 주문입니다.\n");
		}

		//while문 반복을 위해 다시 써주기(메뉴판, 주문 받기)
		printf("\n===== 메뉴 =====\n");
		printf("1. 햄버거: %d원\n", ham);
		printf("2. 콜라: %d원\n", cola);
		printf("3. 치킨: %d원\n", chi);
		printf("================\n");
		printf("메뉴를 선택하세요(주문 완료시 0 입력)\n");

		scanf("%d", &order);

	}

	//결과 화면 출력
	printf("총금액: %d\n", sum);
	printf("맛있게 드세요~\n");

}