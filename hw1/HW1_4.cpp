#include <stdio.h>
void name(void)
{
	printf("=======================\n");
	printf("=======================\n");
}

//�Լ� ������ Ÿ��

void show_menu(void);  //ȭ�鿡 �޴� ���
int func_order(int);   //�Լ��� ���� �޴���ȣ ���� �޾� �� �޴� ���� �����Լ��� ��ȯ �� �ֹ��� ���� ���
int main(void)         //�޴� ���� ��ȯ�޾� �ݺ� ������ �� ���� ���

{
	name();

	//���� ����
	int kim=1500, duk=3000, drink=700; //�� �޴��� ����
	int choice;                        //����ڷκ��� ���� �޴� ��ȣ
	int sum = 0;                       //�� �ֹ� �ݾ� ���� �� �ʱ�ȭ
	int money;                         //����ڷκ��� ���� �� ����

	do
	{
		show_menu();                    //�޴��� ���
		printf("����: ");               //����ڷκ��� �޴� ��ȣ �Է� �ޱ�
		scanf("%d", &choice);

		switch (choice)                 //�޴� ��ȣ�� ���� ��� ����
		{
		case 0: case 1: case 2: case 3: sum += func_order(choice); break;    //0~3�� ��� func_order�Լ� ���� �� �� �ֹ� �ݾ� ���
		default: printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n"); break; //0~3 �̿��� ������ ���

		}


	} while (choice != 0);              //0�� �Է¹����� �ݺ� ����


	printf("�� %d�� �Դϴ�. �󸶸� ���ðڽ��ϱ�?", sum);     //������� �� �Է¹ޱ�
	scanf("%d", &money);
	printf("�Ž������� %d�� �Դϴ�.\n", money - sum);        //�Ž����� ��� �� ���

}

void show_menu()                 //�޴��� ��� ����
{
	printf("===�޴�����===\n");
	printf("1.���   1500\\\n");
	printf("2.������ 3000\\\n");
	printf("3.�����  700\\\n");
	printf("0.����\n");
	printf("==============\n");

}

int func_order(int choice)     //�Լ� ����
{
	int price = 0;                 //��ȯ �� ���� ���� �ʱ�ȭ

	switch (choice)
	{
	case 1: price = 1500; printf("����� �ֹ��ϼ̽��ϴ�.\n"); break;   //�ֹ���ȣ 1�� ���, ���� �ʱ�ȭ ���ֹ� ���� ���
	case 2: price = 3000; printf("�����̸� �ֹ��ϼ̽��ϴ�.\n"); break; //�ֹ���ȣ 2�� ���, ���� �ʱ�ȭ �� �ֹ� ���� ���
	case 3: price = 700; printf("������� �ֹ��ϼ̽��ϴ�.\n"); break;  //�ֹ���ȣ 3�� ���, ���� �ʱ�ȭ �� �ֹ� ���� ���
	case 0:                                                             //�ֹ���ȣ 0�� ���, �ݺ� ����������
		break;
	}

	return price;                                                      //���� �ʱ�ȭ �� ��(�� �޴��� ����) �����ֱ�

}