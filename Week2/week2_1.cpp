#include <stdio.h>
int main(void)
{
	/*����� ���� ���� ���� �� �ʱ�ȭ*/
	int a=3, b=5;
	float c=1.5, d=2.5;
	
	/*���� ���� �˷��ش�.*/
	printf("a=%d b=%d c=%.1f d=%.1f \n", a, b, c, d);

	printf("\n"); /*�� ���*/


	printf("%d + %d = %d\n", a,b, a + b); /*a,b����*/
	printf("%d - %d = %d\n", a, b, a - b); /*a,b����*/
	printf("%d * %d = %d\n", a, b, a * b); /*a,b����*/
	printf("%.1f / %.1f = %.1f\n", c, d, c / d); /*c,d������, �Ҽ��� ù°�ڸ�������*/
}