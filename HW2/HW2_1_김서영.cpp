#include <stdio.h>
#include <string.h>  //���ڿ� �����Լ� �������

//�л� ���� �Լ�
void NAME()
{
	printf("===================\n");
	printf("===================\n");
}


int main()
{
	NAME();               //�л� ���� ���

	char string1[100];    //ó�� �Է¹��� ���ڿ�
	char string2[100];    //��ȯ �� ���ڿ�
	char ini;             //���� �� �� ����
	int length;           //���ڿ� ���� ����


	//����ڷκ��� ���ڿ� �Է¹ޱ�
	printf("���ڿ��� �Է��ϼ���.\n");
	gets_s(string1);
	length = strlen(string1);              //���ڿ��� ���� ���

	for (int i = 0; i < length ;i++)       //���ڿ� ���̸�ŭ �ݺ��ؼ� ���� �Ѱ��� ���캸��
	{
		ini = string1[i];                  //ini�� ���� 1��
		if (ini >= 'A' && ini <= 'Z')      //ini�� �빮���̸�
			ini = ini + 32;                //�ҹ��ڷ� ��ȯ(�ƽ�Ű�ڵ� �̿�)
		else if (ini >= 'a' && ini <= 'z') //ini�� �ҹ����̸�
			ini = ini - 32;                //�빮�ڷ� ��ȯ

		string2[i] = ini;                  //string2�� ���ʷ� ��ȯ�� ���ڵ� ����
	}

	string2[length] = '\0';                //���ڿ��� �������� null�� �ݾ��ش�


	//��� ���
	printf("���� �� ���ڿ�:%s\n", string1);   //ó�� ���ڿ�
	printf("���� �� ���ڿ�:%s\n", string2);   //��ȯ �� ���ڿ�
}