#include <stdio.h>
int main(void)
{
	//����ڿ��Լ� ���� �Է� �䱸
	printf("1~10 ������ ������ �Է��ϼ���:\n");
	
	//���� ���� �� �ʱ�ȭ
	int num;         // �Է¹��� ����
	int sum=1 ;      // factorial ��� ���� ���� ���� �� �ʱ�ȭ
	int i;           // for���� ���� ���� ����

	//����ڿ��Լ� ���� �Է� �ޱ�
	scanf("%d", &num);

	//factorial ���

	if (num >= 1 && num <= 10)                      //num�� 1~10���� ������ ���
	{
		for (i = 1; i <= num; i++)                  //factorial���
		{
			sum *= i;
			printf("%d! = %d\n", i, sum);           //��� ���� �����ֱ�
		}
		printf("\n%d!�� ���� %d�Դϴ�\n", num, sum);//��� �� ���
	}

	else                                           //�� ���� ������ ���
		printf("���� ���� ���Դϴ�.");

}