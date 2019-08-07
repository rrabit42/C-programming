#include <stdio.h>
#define SIZE 20                         //����� 20���� ����

//�Լ����� ������Ÿ��(�� �Լ� ������ ���� �ּ�����)
void input(int[], int);
void output(int[], int);
int sum(int [], int);
void average(int, int, float *);
void maxmin(int[], int, int*, int*);


//�л� ���� ��� �Լ�
void NAME(void)
{
	printf("=========================\n");
	printf("=========================\n");
}


//���� �Լ�(�л��� �Է¹ޱ�, �� �Լ� ȣ���ϱ�, ��� ����ϱ�)
int main(void)
{
	NAME(); //�л� ���� ���


	//���� ����
	int score[SIZE];                  //�л� ���� ���� 1���� ���� �迭
	int total, maxValue, minValue;    //���� �հ�, �ִ�, �ּڰ� ���� ����
	float avg;                        //��� ���� ����
	int realNum;                      //�л� �� ���� ����


	//�л� �� �Է¹ޱ�
	do {
		printf("���� �Է� ���� �л� ����?<1~20>:");
		scanf("%d", &realNum);
	} while (realNum < 1 || realNum>20);      //1~20������ �ƴ� ��� ���Է¹ޱ�



	printf("\n");  //���� ����


	input(score, realNum);                         //�л� ���� �迭�� �Է¹ޱ�
	printf("\n++++++++ ��  �� ++++++++\n");        //��� ���
	output(score, realNum);                        //�� �л� ���� ���
	total = sum(score, realNum);                   //total ������ ���� ���� ��ȯ�ޱ�
	printf("�հ�:%d\n", total);                    //�հ� ���
	average(realNum, total, &avg);                 //avg ������ ��� �ޱ�
	printf("���:%.2f\n",avg);                     //��� ���
	maxmin(score, realNum, &maxValue, &minValue);  //maxValue, minValue�� ���� �ִ�, �ּڰ� �ޱ�
	printf("�ִ�:%d\n",maxValue);                  //�ִ� ���
	printf("�ּ�:%d\n",minValue);                  //�ּڰ� ���

}

//�л� ���� �Է¹޴� �Լ�
void input(int score[], int realNum)
{
	for (int i = 0; i < realNum; i++)               //�ݺ��� �̿��Ͽ� �Է¹��� �л� �� ��ŭ
	{
		printf("�л�%d:", i + 1);                   //�� �迭�� ������ �Է� �޴´�
		scanf("%d", &score[i]);
		if (score[i] < 0 || score[i]>100)           //������ �������(0~100)�� �ƴ� ��
		{
			do {
				printf("�ٽ� �Է����ּ���.\n");     //������� �Է� ������ �ٽ� �Է� �ޱ�
				printf("�л�%d:", i + 1);
				scanf("%d", &score[i]);
			} while (score[i] < 0 || score[i]>100);
		}
	}
}


//�� �л� ���� ��� �Լ�
void output(int score[], int realNum)
{
	printf("�л� ����:");
	for (int i = 0; i < realNum; i++)        //�迭�� ������ �л� �������� �л� �� ��ŭ ����Ѵ�
	{
		printf("%d  ", score[i]);
	}
	printf("\n");                            //��� �������� �ٹٲٱ�

}


//�������� ���� ��ȯ �Լ�
int sum(int score[], int realNum)
{
	int total = 0;                           //���� ���� �ʱ�ȭ
	for (int i = 0;i < realNum;i++)          //�������� �հ踦 ���Ѵ�
	{
		total += score[i];
	}

	return total;                            //�հ� ��ȯ
}


//avg�� ��հ� �Է� �Լ�
void average(int realNum, int total , float *avg)
{
	float average;                             //��� ���� ���� �ʱ�ȭ
	average = total / float(realNum);          //float ���Ŀ� �°� ��� ����ؼ� ����
	*avg = average;                            //avg�� ��հ� ����

}


//�ּڰ�, �ִ� �Է� �Լ�
void maxmin(int score[], int realNum, int*maxValue, int*minValue)
{
	int max = score[0], min = score[0];        //�ִ�, �ּڰ� ������ �ʱⰪ�� �迭�� �� ������ �ʱ�ȭ

	for (int i = 0;i < realNum;i++)            //�迭�� ��� ������� ����
	{
		if (max < score[i])                    //�ִ� ã�Ƽ� max�� ����
			max = score[i];

		if (min > score[i])                    //�ּڰ� ã�Ƽ� min�� ����
			min = score[i];
	}
	*maxValue = max;                           //maxValue�� ã�� �ִ� ����
	*minValue = min;                           //minValue�� ã�� �ּڰ� ����
}