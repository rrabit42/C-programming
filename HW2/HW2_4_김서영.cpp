#include <stdio.h>
#define NUM 10        //�л��� �ִ� 10��

//�����л� ���� ��� �Լ�
void NAME()
{
	printf("===================\n");
	printf("===================\n");
}

//�л� ���� ����ü ���� : �л� ����, �հ�, ��� ��
struct student {
	char ID[20];      //���̵�
	char name[20];    //�л� �̸�
	float Kor;        //���� ����
	float Eng;        //���� ����
	float Math;       //���� ����
	float Sum;        //���� �հ�
	float Avg;        //���
	char Grade;       //����
};

//���α׷��� ����� �Լ����� ������Ÿ��
int score_input(struct student student[]);                      //�л����� �Է¹ް� �л��� ��ȯ �Լ�
void compute_score(struct student student[], int);              //�л� ���� �հ�, ��� ���, ���� ���� �Լ�
char compute_grade(float);                                      //�л� ��� �Է� �޾� �л� ���� ��ȯ �Լ�
void score_output(struct student student[], int, FILE*);        //�� �л� ����, ���� ȭ��� ���Ͽ� ��� �Լ�
void subject_output(struct student student[], int, FILE*);      //���� �ִ�, �ּ�, �հ� ���ϴ� �Լ�
void print_subject_output(float*, float*, float*, int, FILE*);  //���� �ִ�,�ּ�,�հ� ȭ��� ���Ͽ� ��� �Լ�

//���α׷�
int main()
{
	//���� �л� ���� ���
	NAME();

	
	struct student student[NUM];         //�л����� ����ü �迭 ����
	FILE*fp;                             //���� ������ ����
	int cnt;                             //�Է¹��� ������ �л� ��
	fp = fopen("d:\\student.xls", "w");  //���� ���� ���� ���� ����
	cnt = score_input(student);          //�� �л��� ���� �Է��Լ� ȣ�� �� ����� �л� �� ��ȯ �ޱ�
	compute_score(student, cnt);         //�� �л��� ����, ���, ���� ���
	score_output(student, cnt, fp);      //�� �л��� ���� ���
	subject_output(student, cnt, fp);    //���� ���� ��� ���
	fclose(fp);                          //���� �ݱ�
	printf("\"d:\\student.xls\"������ �����Ǿ����ϴ�\n");
	printf("���α׷� ����\n");           //���α׷� ����
}



//�л����� �Է¹ް� �л��� ��ȯ �Լ�
int score_input(struct student student[])
{
	int num;                         //������ �л� �� ����

	//�Է¹��� �л� �� �����
	printf("�л��� ����Դϱ�: ");
	scanf("%d", &num);

	//�л����� ���� student�迭�� ����
	printf("%d���� ������ �Է��ϼ���.\n", num);
	for (int i = 0; i < num; i++)    //�Է¹��� �л� �� ��ŭ �ݺ�
	{
		//���̵�
		printf("\nID: ");
		scanf("%s", student[i].ID);

		//�̸�
		printf("�̸�: ");
		scanf("%s", student[i].name);

		//����
		printf("����: ");
		scanf("%f", &student[i].Kor);
		  //���� ����(0~100��) ��� �� �ٽ� �Է¹ޱ�
		while (student[i].Kor < 0 || student[i].Kor>100)
		{
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			printf("����: ");
			scanf("%f", &student[i].Kor);
		}

		//����
		printf("����: ");
		scanf("%f", &student[i].Eng);
		   //���� ����(0~100��) ��� �� �ٽ� �Է¹ޱ�
		while (student[i].Eng< 0 || student[i].Eng>100)
		{
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			printf("����: ");
			scanf("%f", &student[i].Eng);
		}

		//����
		printf("����: ");
		scanf("%f", &student[i].Math);
		   //���� ����(0~100��) ��� �� �ٽ� �Է¹ޱ�
		while (student[i].Math < 0 || student[i].Math>100)
		{
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			printf("����: ");
			scanf("%f", &student[i].Math);
		}
	}

	return num; //������ �л� �� ��ȯ
}


//�л� ���� �հ�, ��� ���, ���� ���� �Լ�
void compute_score(struct student student[], int num)
{
	float total;                //�� �л� ���� �հ�
	float avg;                  //���� ���

	//��հ� �հ� ���
	for (int i=0; i<num; i++)
		{
		total = student[i].Kor + student[i].Eng + student[i].Math; //�հ�
		avg = total / 3;                                           //���
		student[i].Sum = total;                   //student�迭�� �հ� ����
		student[i].Avg = avg;                     //student �迭�� ��� ����
		student[i].Grade = compute_grade(avg);    //��� �̿��� ���� ��ȯ�޾� student�迭�� ���� ����
		}
}


//�л� ��� �Է� �޾� �л� ���� ��ȯ �Լ�
char compute_grade(float score)
{
	if (score >= 90) return 'A';       //90~100���� A
	else if (score >= 80) return 'B';  //80~89���� B
	else if (score >= 70) return 'C';  //70~79���� C
	else if (score >= 60) return'D';   //60~69���� D
	else return 'F';                   //60�� �̸��� F
}


//�� �л� ����, ���� ȭ��� ���Ͽ� ��� �Լ�
void score_output(struct student student[], int num, FILE* fp)
{
	//���Ͽ� ���
	fprintf(fp, "\n����\tID\t�̸�\t\t����\t����\t����\t�հ�\t���\t����\t\n");
	for (int i = 0; i < num; i++) {
		fprintf(fp, "%d\t%s\t%s\t\t%.0f\t%0.f\t%0.f\t%0.f\t%0.2f\t%c\t\n", i+1, student[i].ID, student[i].name, student[i].Kor, student[i].Eng, student[i].Math, student[i].Sum, student[i].Avg, student[i].Grade);
	} //���ʷ� ����, �̸�, ��������, ��������, ��������, ���� �հ�, ���, ���� ���

	//ȭ�鿡 ���
	printf("\n����\tID\t�̸�\t\t����\t����\t����\t�հ�\t���\t����\t\n");
	for (int i = 0; i < num; i++) {
		printf("%d\t%s\t%s\t\t%.0f\t%0.f\t%0.f\t%0.f\t%0.2f\t%c\t\n", i + 1, student[i].ID, student[i].name, student[i].Kor, student[i].Eng, student[i].Math, student[i].Sum, student[i].Avg, student[i].Grade);
	} //���� ����

}


//���� �ִ�, �ּ�, �հ� ���ϴ� �Լ�
void subject_output(struct student student[], int num, FILE*fp)
{
	float Max[3], Min[3],Total[3];             //���� �ִ�, �ּ�, �հ� �迭
	float K[NUM], E[NUM], M[NUM];              //����, ����, ���� ���� ���� �迭
	float ktotal = 0, etotal = 0, mtotal = 0;  //����, ����, ���� �� �հ� ����

	//�� ���� ���� �迭�� �Է��ϱ�
	for (int i = 0; i < num; i++)      //�Է¹��� �л� �� ��ŭ
	{
		K[i] = student[i].Kor;  //����
		E[i] = student[i].Eng;  //����
		M[i] = student[i].Math; //����
	}

	//�� ���� �ִ�, �ּ� ���ϱ� && ���� ���� �հ� ���ϱ�
	float kmax = K[0], kmin=K[0]; //���� �ʱⰪ ����
	float emax = E[0], emin=E[0]; //���� �ʱⰪ ����
	float mmax = M[0], mmin=M[0]; //���� �ʱⰪ ����

	for (int i = 0; i < num; i++)     //�Է¹��� �л� �� ��ŭ
	{
		//�� ���� �ִ�, �ּ� ���ϱ�
		if (kmax < K[i]) kmax = K[i]; //���� �ִ밪 ���ϱ�
		if (kmin > K[i]) kmin = K[i]; //���� �ּڰ� ���ϱ�
		if (emax < E[i]) emax = E[i]; //���� �ִ� ���ϱ�
		if (emin > E[i]) emin = K[i]; //���� �ּڰ� ���ϱ�
		if (mmax < M[i]) mmax = M[i]; //���� �ִ� ���ϱ�
		if (mmin > M[i]) mmin = M[i]; //���� �ּڰ� ������

		//���� ���� �հ� ���ϱ�
		ktotal += K[i]; //����
		etotal += E[i]; //����
		mtotal += M[i]; //����
	}

	//�ִ�, �ּ�, �հ� �迭�� ���� ���ʷ� �����ϱ�

	 //�ִ밪 �迭
	Max[0] = kmax;     //���� �ִ�
	Max[1] = emax;     //���� �ִ�
	Max[2] = mmax;     //���� �ִ�

	 //�ּڰ� �迭
	Min[0] = kmin;     //���� �ּڰ�
	Min[1] = emin;     //���� �ּڰ�
	Min[2] = mmin;     //���� �ּڰ�

	 //�հ� �迭
	Total[0] = ktotal; //���� �հ�
	Total[1] = etotal; //���� �հ�
	Total[2] = mtotal; //���� �հ�

	//��� ���� �� �Լ��� ����
	print_subject_output(Max, Min, Total, num, fp);
}


//���� �ִ�,�ּ�,�հ� ȭ��� ���Ͽ� ��� �Լ�
void print_subject_output(float* max, float* min, float*total, int num, FILE*fp)
{
	//���Ͽ� ���
	fprintf(fp,"\n����\t�ְ�\t����\t���\t\n");
	fprintf(fp, "����\t%.0f\t%0.f\t%0.1f\n", max[0], min[0], total[0] / num); //���� �ְ�����, ��������, �������
	fprintf(fp, "����\t%.0f\t%0.f\t%0.1f\n", max[1], min[1], total[1] / num); //���� �ְ�����, ��������, �������
	fprintf(fp, "����\t%.0f\t%0.f\t%0.1f\n", max[2], min[2], total[2] / num); //���� �ְ�����, ��������, �������

	//ȭ�鿡 ���
	printf("\n����\t�ְ�\t����\t���\t\n");
	printf("����\t%.0f\t%0.f\t%0.1f\n", max[0], min[0], total[0] / num);      //���ϰ� ���ϳ���
	printf("����\t%.0f\t%0.f\t%0.1f\n", max[1], min[1], total[1] / num);
	printf("����\t%.0f\t%0.f\t%0.1f\n", max[2], min[2], total[2] / num);
}