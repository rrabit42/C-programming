#include<stdio.h>
#define NUM 10                                 //NUM�� 10���� ����

void name(void)                                //�л� ���� ��� �Լ� ����
{
	printf("=======================\n");
	printf("=======================\n");
}

int main(void)
{
	name();                                    //�л� ���� ���



	//�л� �� �Է¹ޱ�

	int num;                                      //�л� �� �Է¹��� ����

	do {
		printf("�л����� ����ΰ���?(1~10)\n");
		scanf("%d", &num);
	} while (num < 1 || num > 10);               //1~10 ����� ����, �� �� ���� �Է½� �ùٸ� ���� �� �Է� ���� ������ �ݺ�






	//�л����� ���� �Է� �ޱ�

	printf("�л� �� %d���� ������ �Է��ϼ���(0~100)\n", num);

	int score[NUM];  //���� �Է� ���� ���ڿ�

	for (int i = 0; i < num; i++) //�л� �� ��ŭ ���� ���� �Է� �ޱ�
	{
		printf("�л�%d: ", i + 1);
		scanf("%d", &score[i]);

		while (score[i] < 0 || score[i] > 100)       //���� ������ 0~100�� ������ �ƴ϶��
		{
			printf("�ٽ� �Է����ּ���(0~100)\n");
			printf("�л�%d: ", i + 1);
			scanf("%d", &score[i]);                  //�ùٸ� ������ �� �Է� �� ���� �ݺ�
		}
	}




	// �� �л��� ���� ����ϱ�

	printf("\n<�� �л��� ����>\n");
	for (int i = 0; i < num; i++)
	{
		printf("�л�%d: %d\n", i + 1, score[i]);
	}


	printf("=======================\n");


	//�л��� ������ �հ�, ���, �ִ밪, �ּҰ� ���

	int sum=0;                        //�հ� ���� �� �ʱ�ȭ
	float average;                    //��� ����
	int max, min;                     //�ִ밪, �ּҰ� ����

	for (int i = 0; i < num; i++)     //�������� �հ� ���ϱ�
		sum += score[i];

	average = float(sum) / num;       //��� ����ϱ�

	max = score[0];                   //�ִ밪 �ʱ�ȭ(���ڿ��� ù° ����)
	min = score[0];                   //�ּҰ� �ʱ�ȭ(���ڿ��� ù° ����)


	//�ִ밪, �ּҰ� ã��


	for (int i = 0; i < num; i++)
	{
		if (max < score[i])     //���ڿ��� �� �� max���� ū ���� ��Ÿ����
			max = score[i];     //�� ���� max�� �ȴ�

		if (min > score[i])     //���ڿ��� �� �� min���� ���� ���� ��Ÿ����
			min = score[i];     //�� ���� min�� �ȴ�
	}


	////�л��� ������ �հ�, ���, �ִ밪, �ּҰ� ���

	printf("�հ�: %d\n", sum);
	printf("���: %.2f\n", average);
	printf("�ִ�: %d\n", max);
	printf("�ּ�: %d\n", min);


}