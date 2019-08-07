#include<stdio.h>
#include<string.h>  //���ڿ����� �Լ��� ������� �ҷ�����
#define SIZE 100    //��ũ���Լ� SIZE�� 100���� ����

//�л� ���� ��� �Լ�
void NAME(void)
{
	printf("====================\n");
	printf("====================\n");
}

//����ü ����
struct employee {
	char name[30];       //����̸�(�ѱ� Ȥ�� ����)
	int position;        //���� 1.���  2.�븮  3.����
	int salary;          //����(����:����)
};
typedef struct employee employee;  //����ü�� employee�� �ٿ� ����

//�Լ����� ������Ÿ��
void nameinput(employee[], int*);    //����ü �迭�� �����̸� �Է��ϴ� �Լ�
void input(employee[], int);         //����ü �迭�� ���ް� ���� �Է��ϴ� �Լ�
void output(employee *, int);        //�� ����� �̸�, ����, ���� ��� �Լ�
float average(employee *, int, int); //���޺��� ���� ��� ��� �� ��� �Լ�



//���� �Լ�
int main(void)
{
	//�л� ���� ȣ��
	NAME();

	//���� ����
	employee worker[SIZE];       //employee����ü�� ������ ����
	int number;                  //���� �ԷµǴ� ����� ��

	nameinput(worker, &number);  //�����̸� �� ������ �����ϱ�
	input(worker, number);       //�����̸� ������ ���� ���ް� ���� �Է��ϱ�

	printf("\n<��     ��>\n");
	output(worker, number);      //�� ������ �̸�, ����, ���� ��� ���
	printf("\n����� ���� ���:%.2f", average(worker, 1, number));  //����� ���� ���
	printf("\n�븮�� ���� ���:%.2f", average(worker, 2, number));  //�븮�� ���� ���
	printf("\n����� ���� ���:%.2f", average(worker, 3, number));  //����� ���� ���
	return 0;
}


//���� �̸� �Է� �Լ�
void nameinput(employee worker[], int* num)
{
	int count = 0;                                  //���� �Է��ϴ� ������ ���� ����
	printf("<�����̸��Է�>(����� \"0\"�Է�)\n");
	for (int i = 0; i < SIZE; i++) {
		printf("�����̸�:");
		gets_s(worker[i].name);                     //���� �̸� �Է� �ޱ�(���۷� ���� ���������� �ʵ���)
		if (strcmp(worker[i].name, "0") == 0)       //"0"�Է� �� ����
			break;
		count += 1;                                 //����� ����(0�� ������� ���� ����)
	}
	*num = count;                                   //������� num�� ����
}


//���� ����, ���� �Է� �Լ�
void input(employee worker[], int num)
{
	printf("\n<��������,���������Է�>\n");
	for (int i = 0; i < num; i++)                      //�Է� ���� ��� �� ��ŭ
	{
		printf("\n�����̸�:%s\n", worker[i].name);
		do {
			printf("��������(1.��� 2.�븮 3.����):");
			scanf("%d", &worker[i].position);          //���� �Է� �ޱ�
		} while ((worker[i].position <= 0) || (worker[i].position > 3)); //������ ���� �ʴ� �� �Է� �� �ٽ� �����

		do {
			printf("��������(����:����):");
			scanf("%d", &worker[i].salary);            //���� �Է� �ޱ�
		} while (worker[i].salary < 0);                //������ ���� �ʴ� �� �Է� �� �ٽ� �����
	}
}


//������ �̸�, ����, ���� ����Լ�
void output(employee *worker, int num)
{
	printf("�̸�\t\t����\t����\t\n");
	for (int i = 0; i < num; i++)      //�Է¹��� ����� ��ŭ �ݺ�
	{
		switch (worker[i].position)    //������ �ѱ۷� ������ֱ� ����
		{
		case 1: //1 �϶��� ���, �̸�, ���� ���
			printf("%s\t%s\t%d\n", worker[i].name, "���", worker[i].salary);
			break;
		case 2: //2 �϶��� �븮, �̸�, ���� ���
			printf("%s\t%s\t%d\n", worker[i].name, "�븮", worker[i].salary);
			break;
		case 3: //3 �϶��� ����, �̸�, ���� ���
			printf("%s\t%s\t%d\n", worker[i].name, "����", worker[i].salary);
			break;
		}
	}
}


//���޺� ��� ���� ��� �� ��� �Լ�
float average(employee*worker, int position, int number)
{
	int count = 0, total = 0;                //���ʷ� ���޺� �ο���, ���޺� ���� ���� ����
	for (int i = 0; i < number; i++)         //�Է¹��� ����� ��� �����Ѵ�
	{
		if (worker[i].position == position)  //�� �߿��� �Է��� position�μ��� ���� ���� ���� �������
		{
			count += 1;                      //���� ����
			total += worker[i].salary;       //�׵��� ������ ��� ���Ѵ�
		}
	}
	return float(total) / count;             //���(�Ǽ�)�� �����ش�
}