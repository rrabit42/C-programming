#include<stdio.h>
void name(void)
{
	printf("=======================\n");
	printf("=======================\n");
}

//�Լ� ������ Ÿ��
double add(double x, double y);              //���� �Լ�
double substraction(double x, double y);     //���� �Լ�
double multiplication(double x, double y);   //���� �Լ�
double division(double x, double y);         //������ �Լ�

int main(void)
{
	name();

	//�Է¹��� ������ ���� ����
	double x;  //����1
	char cal;  //���� ��ȣ
	double y;  //����2


	//����� ���� �Է� �ޱ�
	printf("<����>\n");
	printf("����:");
	scanf("%lf%c%lf", &x, &cal, &y);


	switch (cal) //cal�� ��ȣ�� ���� ȣ���ϴ� �Լ��� �ٸ�

		//�Ҽ��� ��°�ڸ������� ���(���� ���� ����)
	{
	case '+': printf("%.2lf %c %.2lf = %.2lf", x, cal, y, add(x, y)); break;               //'+'��ȣ �Է¹����� ���� �Լ� ȣ��
	case '-': printf("%.2lf %c %.2lf = %.2lf", x, cal, y, substraction(x, y)); break;      //'-'��ȣ�� ���� �Լ� ȣ��
	case '*': printf("%.2lf %c %.2lf = %.2lf", x, cal, y, multiplication(x, y)); break;    //'*'��ȣ�� ���� �Լ�
	case '/': printf("%.2lf %c %.2lf = %.2lf", x, cal, y, division(x, y)); break;          //'/'��ȣ�� ������ �Լ�
	default: printf("�߸� �Է��ϼ̽��ϴ�\n");                                              //������ ���� �Է� ��

	}


}


double add(double x, double y)           //���� �Լ� ����
{
	double result;                       //��� �� �ʱ�ȭ
	result = x + y;                      //���� ���
	return result;                       //����� ��ȯ
}

double substraction(double x, double y)  //���� �Լ� ����
{
	double result;                       //���� ����
	result = x - y;
	return result;
}

double multiplication(double x, double y)//���� �Լ� ����
{
	double result;                       //���� ����
	result = x * y;
	return result;
}

double division(double x, double y)      //���� �Լ� ����
{
	double result;                       //���� ����
	result = x - y;
	return result;
}