#include <stdio.h>
int main(void)
{
	/*계산을 위한 변수 지정 및 초기화*/
	int a=3, b=5;
	float c=1.5, d=2.5;
	
	/*변수 값을 알려준다.*/
	printf("a=%d b=%d c=%.1f d=%.1f \n", a, b, c, d);

	printf("\n"); /*줄 띄기*/


	printf("%d + %d = %d\n", a,b, a + b); /*a,b덧셈*/
	printf("%d - %d = %d\n", a, b, a - b); /*a,b뺄셈*/
	printf("%d * %d = %d\n", a, b, a * b); /*a,b곱셈*/
	printf("%.1f / %.1f = %.1f\n", c, d, c / d); /*c,d나눗셈, 소숫점 첫째자리까지만*/
}