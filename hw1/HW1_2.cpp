#include <stdio.h>
void name(void)
{
	printf("=======================\n");
	printf("=======================\n");
}

int main(void)
{

	name();

	//���� ����
	int num;                                      //����ڿ��� �Է� ���� ����
	int i,j,k;                                    //�ݺ����� ���� ����


	//����ڿ��� ���� �Է¹޴´�
	printf("Enter the height of the triangle:");
	scanf("%d", &num);


	//�Ƕ�̵��� �����
	if (num >= 1 && num <= 20)                    //������ 1~20 ���̾�� �Ѵ�.
	{
		for (i = 1;i <= num; i++)
		{
			for (k = 1;k <=(num - i);k++)         //*�� ������� �ǵ��� space ����
				printf(" ");
			for (j = 1; j <= (i * 2 - 1); j++)    //* ���(*�� Ȧ����)
					printf("*");
			printf("\n");                         //�� �� ��� ������ �ٹٲ�
		}
	}

	else                                          //���� ���� ���� ���
		printf("�߸��� �Է��Դϴ�\n");

}