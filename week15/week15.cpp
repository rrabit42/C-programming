#include<stdio.h>      //�⺻�Լ� �������
#include<stdlib.h>     //�����Ҵ� ���� ��� ����

//�л����� ��� ��ũ��
#define NAME printf("=========================\n");\
printf("=========================\n")

//�迭�� ����� ���ڵ��� ��� ����ϴ� �Լ��� ������Ÿ��
float func(int *, int num);

int main(void)
{
	//�л����� ���
	NAME;

	//������
	int num;           //�׷��ο� ��
	int *arr = NULL;   //�����޸� ����ų ������ �� �ʱ�ȭ

	//0 �Է½ñ��� �ݺ��ϱ�
	while (1)
	{
		//����ڿ��� �׷��ο� �Է¹ޱ�
		num = printf("\n�׷��ο��� ����Դϱ�?<0~100>\n");
		scanf("%d", &num);

		//����(0~100)���� ��� ���̸� �ٽ� �Է¹ޱ�
		if (num < 0 || num>100)
		{
			printf("�ο��� 0���� 100�����Դϴ�.\n");
			continue;
		}
		else if (num == 0) break; //�Է¹��� ���� 0�̸� �ݺ��� Ż��

		//�׷��ο� �� ��ŭ ���� �޸� �Ҵ��ϱ�
		arr = (int*)malloc(sizeof(int)*num);

		//���� ������ ���� null�̸�,
		if (arr == NULL)
		{
			printf("���� �޸� �Ҵ� ����\n");
			return -1;                         //���� �޸� �Ҵ� ������ ���̹Ƿ� ������ ���α׷� ������
		}

		//������ ���� �����̸�, �׷������� ���̸� �޸𸮹迭�� �����ϱ�
		printf("�׷����� ���̸� �Է��ϼ���<0~120>\n");
		for (int i = 0; i < num; i++)                       //��� �� ��ŭ ���� �Է¹ޱ�
		{
			scanf("%d", &arr[i]);
			while (arr[i] < 0 || arr[i]>100)                //���̰� �������� ��� ���̸�
			{
				printf("���̴� 0���� 120 �����Դϴ�.\n");   //���� ���� �ȳ��� �ְ�,
				scanf("%d", &arr[i]);                       //���� ���� �Է½ñ��� �ٽ� �Է¹ޱ�
			}
		}

		//���α׷� ��� ���
		printf("�׷����� ��� ���̴� %.2f�Դϴ�\n", func(arr, num)); //�׷��� ��� ���̸� �Լ� ȣ���ؼ� ���

		free(arr);   //��� �������� �Ҵ��ߴ� �޸� ����
		arr = NULL;  //NULL�� ������ �ش�
	}

	//�ݺ��� ������ ���α׷� ���� �����Ѵ�
	printf("���α׷��� �����մϴ�.\n");
	return 0;
}

//�׷����� ��� ���� ���ϴ� �Լ�
float func(int *arr, int num)       //���ڷδ� �����Ϳ� �׷� �ο� �� �ޱ�
{
	int sum = 0;                    //�հ� ����
	for (int i = 0; i < num; i++)   //�׷� �ο� �� ��ŭ �ݺ��ؼ�
	{
		sum += arr[i];              //���� �հ� ���ϱ�
	}
	return float(sum) / float(num); //�׷��� ��� ���� ��ȯ
}