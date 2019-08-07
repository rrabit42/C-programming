#include <stdio.h>
#define NUM 10        //학생수 최대 10명

//과제학생 정보 출력 함수
void NAME()
{
	printf("===================\n");
	printf("===================\n");
}

//학생 정보 구조체 선언 : 학생 점수, 합계, 평균 등
struct student {
	char ID[20];      //아이디
	char name[20];    //학생 이름
	float Kor;        //국어 점수
	float Eng;        //영어 점수
	float Math;       //수학 점수
	float Sum;        //점수 합계
	float Avg;        //평균
	char Grade;       //학점
};

//프로그램에 사용할 함수들의 프로토타입
int score_input(struct student student[]);                      //학생정보 입력받고 학생수 반환 함수
void compute_score(struct student student[], int);              //학생 점수 합계, 평균 계산, 학점 저장 함수
char compute_grade(float);                                      //학생 평균 입력 받아 학생 학점 반환 함수
void score_output(struct student student[], int, FILE*);        //각 학생 정보, 점수 화면과 파일에 출력 함수
void subject_output(struct student student[], int, FILE*);      //과목별 최대, 최소, 합계 구하는 함수
void print_subject_output(float*, float*, float*, int, FILE*);  //과목별 최대,최소,합계 화면과 파일에 출력 함수

//프로그램
int main()
{
	//과제 학생 정보 출력
	NAME();

	
	struct student student[NUM];         //학생정보 구조체 배열 선언
	FILE*fp;                             //파일 포인터 선언
	int cnt;                             //입력받을 실질적 학생 수
	fp = fopen("d:\\student.xls", "w");  //쓰기 모드로 엑셀 파일 연다
	cnt = score_input(student);          //각 학생의 점수 입력함수 호출 후 결과로 학생 수 반환 받기
	compute_score(student, cnt);         //각 학생의 총점, 평균, 학점 계산
	score_output(student, cnt, fp);      //각 학생의 성적 출력
	subject_output(student, cnt, fp);    //과목별 점수 통계 출력
	fclose(fp);                          //파일 닫기
	printf("\"d:\\student.xls\"파일이 생성되었습니다\n");
	printf("프로그램 종료\n");           //프로그램 종료
}



//학생정보 입력받고 학생수 반환 함수
int score_input(struct student student[])
{
	int num;                         //실질적 학생 수 변수

	//입력받을 학생 수 물어보기
	printf("학생은 몇명입니까: ");
	scanf("%d", &num);

	//학생들의 정보 student배열에 저장
	printf("%d명의 정보를 입력하세요.\n", num);
	for (int i = 0; i < num; i++)    //입력받을 학생 수 만큼 반복
	{
		//아이디
		printf("\nID: ");
		scanf("%s", student[i].ID);

		//이름
		printf("이름: ");
		scanf("%s", student[i].name);

		//국어
		printf("국어: ");
		scanf("%f", &student[i].Kor);
		  //점수 범위(0~100점) 벗어날 시 다시 입력받기
		while (student[i].Kor < 0 || student[i].Kor>100)
		{
			printf("잘못입력하셨습니다.\n");
			printf("국어: ");
			scanf("%f", &student[i].Kor);
		}

		//영어
		printf("영어: ");
		scanf("%f", &student[i].Eng);
		   //점수 범위(0~100점) 벗어날 시 다시 입력받기
		while (student[i].Eng< 0 || student[i].Eng>100)
		{
			printf("잘못입력하셨습니다.\n");
			printf("영어: ");
			scanf("%f", &student[i].Eng);
		}

		//수학
		printf("수학: ");
		scanf("%f", &student[i].Math);
		   //점수 범위(0~100점) 벗어날 시 다시 입력받기
		while (student[i].Math < 0 || student[i].Math>100)
		{
			printf("잘못입력하셨습니다.\n");
			printf("수학: ");
			scanf("%f", &student[i].Math);
		}
	}

	return num; //실질적 학생 수 반환
}


//학생 점수 합계, 평균 계산, 학점 저장 함수
void compute_score(struct student student[], int num)
{
	float total;                //각 학생 점수 합계
	float avg;                  //점수 평균

	//평균과 합계 계산
	for (int i=0; i<num; i++)
		{
		total = student[i].Kor + student[i].Eng + student[i].Math; //합계
		avg = total / 3;                                           //평균
		student[i].Sum = total;                   //student배열에 합계 저장
		student[i].Avg = avg;                     //student 배열에 평균 저장
		student[i].Grade = compute_grade(avg);    //평균 이용해 학점 반환받아 student배열에 학점 저장
		}
}


//학생 평균 입력 받아 학생 학점 반환 함수
char compute_grade(float score)
{
	if (score >= 90) return 'A';       //90~100점은 A
	else if (score >= 80) return 'B';  //80~89점은 B
	else if (score >= 70) return 'C';  //70~79점은 C
	else if (score >= 60) return'D';   //60~69점은 D
	else return 'F';                   //60점 미만은 F
}


//각 학생 정보, 점수 화면과 파일에 출력 함수
void score_output(struct student student[], int num, FILE* fp)
{
	//파일에 출력
	fprintf(fp, "\n순번\tID\t이름\t\t국어\t영어\t수학\t합계\t평균\t학점\t\n");
	for (int i = 0; i < num; i++) {
		fprintf(fp, "%d\t%s\t%s\t\t%.0f\t%0.f\t%0.f\t%0.f\t%0.2f\t%c\t\n", i+1, student[i].ID, student[i].name, student[i].Kor, student[i].Eng, student[i].Math, student[i].Sum, student[i].Avg, student[i].Grade);
	} //차례로 순번, 이름, 국어점수, 영어점수, 수학점수, 점수 합계, 평균, 학점 출력

	//화면에 출력
	printf("\n순번\tID\t이름\t\t국어\t영어\t수학\t합계\t평균\t학점\t\n");
	for (int i = 0; i < num; i++) {
		printf("%d\t%s\t%s\t\t%.0f\t%0.f\t%0.f\t%0.f\t%0.2f\t%c\t\n", i + 1, student[i].ID, student[i].name, student[i].Kor, student[i].Eng, student[i].Math, student[i].Sum, student[i].Avg, student[i].Grade);
	} //위와 동일

}


//과목별 최대, 최소, 합계 구하는 함수
void subject_output(struct student student[], int num, FILE*fp)
{
	float Max[3], Min[3],Total[3];             //과목별 최대, 최소, 합계 배열
	float K[NUM], E[NUM], M[NUM];              //국어, 영어, 수학 과목별 점수 배열
	float ktotal = 0, etotal = 0, mtotal = 0;  //국어, 영어, 수학 총 합계 변수

	//각 과목별 점수 배열에 입력하기
	for (int i = 0; i < num; i++)      //입력받은 학생 수 만큼
	{
		K[i] = student[i].Kor;  //국어
		E[i] = student[i].Eng;  //영어
		M[i] = student[i].Math; //수학
	}

	//각 과목별 최대, 최소 구하기 && 과목별 점수 합계 구하기
	float kmax = K[0], kmin=K[0]; //국어 초기값 설정
	float emax = E[0], emin=E[0]; //영어 초기값 설정
	float mmax = M[0], mmin=M[0]; //수학 초기값 설정

	for (int i = 0; i < num; i++)     //입력받은 학생 수 만큼
	{
		//각 과목별 최대, 최소 구하기
		if (kmax < K[i]) kmax = K[i]; //국어 최대값 구하기
		if (kmin > K[i]) kmin = K[i]; //국어 최솟값 구하기
		if (emax < E[i]) emax = E[i]; //영어 최댓값 구하기
		if (emin > E[i]) emin = K[i]; //영어 최솟값 구하기
		if (mmax < M[i]) mmax = M[i]; //수학 최댓값 구하기
		if (mmin > M[i]) mmin = M[i]; //영어 최솟갑 수가히

		//과목별 점수 합계 구하기
		ktotal += K[i]; //국어
		etotal += E[i]; //영어
		mtotal += M[i]; //수학
	}

	//최대, 최소, 합계 배열에 점수 차례로 대입하기

	 //최대값 배열
	Max[0] = kmax;     //국어 최댓값
	Max[1] = emax;     //영어 최댓값
	Max[2] = mmax;     //수학 최댓값

	 //최솟값 배열
	Min[0] = kmin;     //국어 최솟값
	Min[1] = emin;     //영어 최솟값
	Min[2] = mmin;     //수학 최솟값

	 //합계 배열
	Total[0] = ktotal; //국어 합계
	Total[1] = etotal; //영어 합계
	Total[2] = mtotal; //수학 합계

	//출력 위해 위 함수에 전달
	print_subject_output(Max, Min, Total, num, fp);
}


//과목별 최대,최소,합계 화면과 파일에 출력 함수
void print_subject_output(float* max, float* min, float*total, int num, FILE*fp)
{
	//파일에 출력
	fprintf(fp,"\n과목\t최고\t최저\t평균\t\n");
	fprintf(fp, "국어\t%.0f\t%0.f\t%0.1f\n", max[0], min[0], total[0] / num); //국어 최고점수, 최저점수, 평균점수
	fprintf(fp, "영어\t%.0f\t%0.f\t%0.1f\n", max[1], min[1], total[1] / num); //영어 최고점수, 최저점수, 평균점수
	fprintf(fp, "수학\t%.0f\t%0.f\t%0.1f\n", max[2], min[2], total[2] / num); //수학 최고점수, 최저점수, 평균점수

	//화면에 출력
	printf("\n과목\t최고\t최저\t평균\t\n");
	printf("국어\t%.0f\t%0.f\t%0.1f\n", max[0], min[0], total[0] / num);      //파일과 동일내용
	printf("영어\t%.0f\t%0.f\t%0.1f\n", max[1], min[1], total[1] / num);
	printf("수학\t%.0f\t%0.f\t%0.1f\n", max[2], min[2], total[2] / num);
}