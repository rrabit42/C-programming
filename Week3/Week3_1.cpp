#include <stdio.h>

int main(void)
{
	//����ڿ��� �Է� ���� ���� 3�� ����
	int a, b, c;

	//����ڿ��� �Է� ��û�ϱ�
	printf("���� 3���� �Է��ϼ���\n");
	scanf("%d%d%d", &a, &b, &c);

	//��� ȭ�� ���
	printf("\n�� ����:%d,%d,%d\n", a, b, c);

	//�հ�� ����� ���ϱ� ���� ���� ����
	int sum;
	double average;

	//�հ�� ����� ���ϱ� ���� ���
	sum = a + b + c;
	average = (float) (a + b + c) / 3;

	//��� ȭ�� ���
	printf("�� ������ ��:%d\n", sum);
	printf("�� ������ ��:%.2f\n", average);
}