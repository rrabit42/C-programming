#include <stdio.h>

int main(void)
{
	//사용자에게 입력받을 금액 변수 지정
	int money;

	//사용자에게 금액 입력 받기
	printf("금액입력(10~10000):");
	scanf("%d", &money);


	//동전개수 결과 출력화면
	printf("\n");
	printf("<동전개수>\n");


	//동전개수 계산을 위한 변수 지정
	int fivef, onef, fivet, onet; //순서대로 500원,100원,50원,10원 변수
	int a, b, c; //동전 개수를 계산하기 위해 중간 계산을 수행할 변수 지정



	//500원 개수 구하기
	fivef = money / 500;

	//100원 개수 구하기
	a = money % 500;
	onef = a / 100;

	//50원 개수 구하기
	b = a % 100;
	fivet = b / 50;

	//10원 개수 구하기
	c = b % 50;
	onet = c / 10;

	//결과 화면 출력
	printf("500원:%d개\n", fivef);
	printf("100원:%d개\n", onef);
	printf("50원:%d개\n", fivet);
	printf("10원:%d개\n", onet);

	//최소동전의 개수를 구하기 위해 변수 지정
	int sum;

	//동전 개수 합치기
	sum = fivef + onef + fivet + onet;

	//최종 결과 화면 출력
	printf("최소 동전의 개수: %d개\n", sum);
}
