#include <stdio.h>
int main(void)
{
	/*해답 도출을 위해 변수를 지정한다.*/
	double gram; /*물분자의 질량*/
	int water; /*물1쿼트의 질량*/
	int amount; /*물의 양*/

	gram = 3.0e-23;
	water = 950;
	amount = 1000;

	/*소숫점에 알맞게 퍼센트form을 지정한다.*/

	printf("물분자 질량: %.1eg\n", gram);
	printf("물1쿼트 : %dg\n", water);

	printf("\n"); /*줄 띄기*/

	/*물이 1000쿼트 있을 때 그 안에 들어있는 물분자의 개수를 계산한다.*/
	printf("%d쿼트의 물은 %dg이고 %.2e개, 혹은 %.0f개의 물분자가 있습니다.\n", amount, water*amount, (water*amount) / gram, (water*amount) / gram);



}