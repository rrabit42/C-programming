#include <stdio.h>
int main(void)
{
	//���� �ջ��� ���� �ݾ� ���� �� �ʱ�ȭ;
	int ham = 4000, cola = 2000, chi = 3000;

	//�޴��� ���
	printf("===== �޴� =====\n");
	printf("1. �ܹ���: %d��\n", ham);
	printf("2. �ݶ�: %d��\n", cola);
	printf("3. ġŲ: %d��\n", chi);
	printf("================\n");
	printf("�޴��� �����ϼ���(�ֹ� �Ϸ�� 0 �Է�)\n");
	
	//�ֹ� ���� ����
	int order;

	//���� �ջ��� ���� ����
	int sum = 0;

	//����ڷκ��� �ֹ� �ޱ�
	scanf("%d", &order);

	//0�� �Է��� ���� ����� �����
	while (order != 0)
	{

		//�Է¹��� �ֹ� ��ȣ�� ���� �ֹ��� ���� �̸� ��� �� ���� ���

		switch (order)
		{
		case 1: printf("�ܹ��Ÿ� �ֹ��ϼ̽��ϴ�.\n"); sum += ham; break;  // 1. �ܹ��� �ֹ� ��
		case 2: printf("�ݶ� �ֹ��ϼ̽��ϴ�.\n"); sum += cola; break;   // 2. �ݶ� �ֹ� ��
		case 3: printf("ġŲ�� �ֹ��ϼ̽��ϴ�.\n"); sum += chi; break;    // 3. ġŲ �ֹ� ��
		default: printf("�߸��� �ֹ��Դϴ�.\n");
		}

		//while�� �ݺ��� ���� �ٽ� ���ֱ�(�޴���, �ֹ� �ޱ�)
		printf("\n===== �޴� =====\n");
		printf("1. �ܹ���: %d��\n", ham);
		printf("2. �ݶ�: %d��\n", cola);
		printf("3. ġŲ: %d��\n", chi);
		printf("================\n");
		printf("�޴��� �����ϼ���(�ֹ� �Ϸ�� 0 �Է�)\n");

		scanf("%d", &order);

	}

	//��� ȭ�� ���
	printf("�ѱݾ�: %d\n", sum);
	printf("���ְ� �弼��~\n");

}