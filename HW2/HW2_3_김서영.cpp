#include <stdio.h>

#define ROW 5        //�� ��� ����
#define COLUMN 7     //�� ��� ����


//�л� ���� ��� �Լ�
void NAME()
{
	printf("===================\n");
	printf("===================\n");
}

//�¼� �����ִ� �Լ��� ������Ÿ��
void viewSeats(int [][COLUMN]);

int main()
{
	NAME();                 //�л� ���� ���

	int seat[ROW][COLUMN];  //�¼� �迭
	int row, column;        //�Է¹��� ��, �� ����
	

	//�迭�� 0���� �ʱ�ȭ
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
			seat[i][j] = 0;
	}


	//�¼� �����ϱ�
	while (1){
		viewSeats(seat);                     //��밡���� �¼� �����ֱ�
		printf("�� �¼��� �������ּ���.(�� �¼�-0/����� �¼�-1/���� 9 9 �Է�)");
		scanf("%d %d", &row, &column);       //����ڷκ��� �¼� �Է� �ޱ�
		if (row == 9 && column == 9) break;  //9 9�Է½� ����
		seat[row][column] = 1;               //9 9�ƴ� �¼� �Է½� �¼� �������ֱ�

	}
}


//�¼� �����ִ� �Լ�
void viewSeats(int seat[][COLUMN])            //2���� �迭�� ���ڷ� �޴´�
{
	printf("\n��/��| 0\t1\t2\t3\t4\t5\t6\t");  //�¼�ǥ ����ϱ�
	printf("\n------------------------------------------------------------------\n");
		for (int i = 0; i < ROW; i++){
			printf("    %d| %d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",i,seat[i][0],seat[i][1],seat[i][2],seat[i][3],seat[i][4],seat[i][5],seat[i][6]);
	}
}
