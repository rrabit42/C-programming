#include <stdio.h>
int main(void)
{
	/*�ش� ������ ���� ������ �����Ѵ�.*/
	double gram; /*�������� ����*/
	int water; /*��1��Ʈ�� ����*/
	int amount; /*���� ��*/

	gram = 3.0e-23;
	water = 950;
	amount = 1000;

	/*�Ҽ����� �˸°� �ۼ�Ʈform�� �����Ѵ�.*/

	printf("������ ����: %.1eg\n", gram);
	printf("��1��Ʈ : %dg\n", water);

	printf("\n"); /*�� ���*/

	/*���� 1000��Ʈ ���� �� �� �ȿ� ����ִ� �������� ������ ����Ѵ�.*/
	printf("%d��Ʈ�� ���� %dg�̰� %.2e��, Ȥ�� %.0f���� �����ڰ� �ֽ��ϴ�.\n", amount, water*amount, (water*amount) / gram, (water*amount) / gram);



}