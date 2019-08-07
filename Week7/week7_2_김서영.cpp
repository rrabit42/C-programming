#include<stdio.h>
#include<math.h>

void name(void)
{
	printf("=======================\n");
	printf("��\n");
	printf("����������\n");
	printf("����Դϴ�\n");
	printf("=======================\n");
}

//�Լ� ������ Ÿ��
int getLength(int, int);               //���� ��� �Լ�
int getArea(int, int, int, int);       //���� ��� �Լ�
int getPerimeter(int, int, int, int);  //�ѷ� ��� �Լ�


int main(void)
{
	name();


	//��ǥ ������
	int x1, y1, x2, y2;


	//����ڷκ��� (x1,y1)��ǥ�� �Է� �ޱ�
	printf("(x1, y1) ��ǥ �Է�: ");
	scanf("%d %d", &x1, &y1);



	if (x1 >= 0 && y1 >= 0)                         //0�̻��� ���� ��� 
	{
		                                            //(x1,y1)�� ���������� �Է� ������ (x2,y2)�Է¹ޱ�
		printf("(x2, y2) ��ǥ �Է�: ");
		scanf("%d %d", &x2, &y2);
	}
	else                                            //0 �̸��� ���� �ԷµǸ� ���� ������ �Էµ� ������ �ݺ�
	{
		do
		{
			printf("x1,y1�� ����Դϴ�.\n");
			printf("(x1, y1) ��ǥ �Է�: ");
			scanf("%d %d", &x1, &y1);

		} while (x1 < 0 && y1 < 0);


		printf("(x2, y2) ��ǥ �Է�: ");	            //���� ���� �ԷµǸ� (x2,y2) ��ǥ�� �Է� �ޱ�
		scanf("%d %d", &x2, &y2);
	}



	
	if (x2 >= 0 && y2 > 0)                           //x2,y2�� 0�̻��� ���� �Է� �޴´�
	{
		printf("(x1, y1) = (%d, %d), (x2, y2) = (%d, %d)\n", x1, y1, x2, y2); //��ǥ�� Ȯ��
	}
	else
	{
		do
		{
			printf("x2,y2�� ����Դϴ�.\n");         //���� ���� �Է� ������ �ٽ� �Է� �ޱ�
			printf("(x2, y2) ��ǥ �Է�: ");
			scanf("%d %d", &x2, &y2);
		} while (x2 < 0 && y2 < 0);

		printf("\n(x1, y1) = (%d, %d), (x2, y2) = (%d, %d)\n", x1, y1, x2, y2); //���� ���� �ȿ��� �Է� ������ ��ǥ�� Ȯ��
	}


	//�Լ� ȣ���Ͽ� ��ǥ������ �̷�� ���簢���� ���� ����� ���
	printf("���簢���� �ʺ�� %d�Դϴ�.\n",getLength(x1,x2));              //���簢���� �ʺ�
	printf("���簢���� ���̴� %d�Դϴ�.\n",getLength(y1,y2));              //���簢���� ����
	printf("���簢���� ������ %d�Դϴ�.\n",getArea(x1,x2,y1,y2));          //���簢���� ����
	printf("���簢���� �ѷ��� %d�Դϴ�.\n",getPerimeter(x1,x2,y1,y2));     //���簢���� �ѷ�

}


//���� ��� ���� �Լ�
int getLength(int a, int b)
{
	int result;           //��� ���� ����
	result = abs(a - b);  //���밪 �Լ� ����Ͽ� ���� ���ϱ�
	return result;        //����� ��ȯ
}

//���� ��� �Լ� ����(���� ����)
int getArea(int a, int b, int c, int d)
{
	int area;
	area = abs(a - b)*abs(c - d);
	return area;
}

//�ѷ� ��� �Լ� ����(���� ����)
int getPerimeter(int a, int b, int c, int d)
{
	int length;
	length = 2 * abs(a - b) + 2 * abs(c - d);
	return length;
}

