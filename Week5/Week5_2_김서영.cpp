#include <stdio.h>
int main(void)
{

//��������� �Է¹��� '��' ���� ����
	int month;

//����ڿ��� ���� �Է¹ޱ�
	printf("Choose the month you like.\n");
	scanf("%d", &month);

//����ڿ��� �Է¹��� '��'�� �̿��� �����ϴ� ������ �������� �˷��ش�.
	switch(month)
	{
	case 3:
	case 4:
	case 5:
		printf("You like spring\n"); //3,4,5���� spring
		break;
	case 6:
	case 7:
	case 8:
		printf("You like summer\n"); //6,7,8���� summer
		break;
	case 9:
	case 10:
	case 11:
		printf("You like fall\n");  //9,10,11���� fall
		break;
	case 12:
	case 1:
	case 2:
		printf("You like winter\n");//12,1,2���� winter
		break;
	default:
		printf("Wrong input\n");    //�� �δ��� �ƴ� �ٸ� ������ �Է��� ���� �߸��� �Է��̶�� ���
		break;
	}

}
