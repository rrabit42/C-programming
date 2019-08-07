#include<stdio.h>
#include<string.h>  //문자열관련 함수의 헤더파일 불러오기
#define SIZE 100    //매크로함수 SIZE를 100으로 선언

//학생 정보 출력 함수
void NAME(void)
{
	printf("====================\n");
	printf("====================\n");
}

//구조체 정의
struct employee {
	char name[30];       //사원이름(한글 혹은 영어)
	int position;        //직급 1.사원  2.대리  3.과장
	int salary;          //월급(단위:만원)
};
typedef struct employee employee;  //구조체를 employee로 줄여 쓴다

//함수들의 프로토타입
void nameinput(employee[], int*);    //구조체 배열에 직원이름 입력하는 함수
void input(employee[], int);         //구조체 배열에 직급과 월급 입력하는 함수
void output(employee *, int);        //각 사원의 이름, 직급, 월급 출력 함수
float average(employee *, int, int); //직급별로 월급 평균 계산 및 출력 함수



//메인 함수
int main(void)
{
	//학생 정보 호출
	NAME();

	//변수 선언
	employee worker[SIZE];       //employee구조체를 가지는 변수
	int number;                  //실제 입력되는 사원의 수

	nameinput(worker, &number);  //직원이름 및 직원수 결정하기
	input(worker, number);       //직원이름 각각에 대해 직급과 월급 입력하기

	printf("\n<결     과>\n");
	output(worker, number);      //각 직원의 이름, 직급, 월급 모두 출력
	printf("\n사원급 월급 평균:%.2f", average(worker, 1, number));  //사원급 월급 평균
	printf("\n대리급 월급 평균:%.2f", average(worker, 2, number));  //대리급 월급 평균
	printf("\n과장급 월급 평균:%.2f", average(worker, 3, number));  //과장급 월급 평균
	return 0;
}


//직원 이름 입력 함수
void nameinput(employee worker[], int* num)
{
	int count = 0;                                  //실제 입력하는 직원수 세는 변수
	printf("<직원이름입력>(종료시 \"0\"입력)\n");
	for (int i = 0; i < SIZE; i++) {
		printf("직원이름:");
		gets_s(worker[i].name);                     //직원 이름 입력 받기(버퍼로 인해 오류생기지 않도록)
		if (strcmp(worker[i].name, "0") == 0)       //"0"입력 시 종료
			break;
		count += 1;                                 //사원수 세기(0은 사원으로 세지 않음)
	}
	*num = count;                                   //사원수를 num에 대입
}


//직원 직급, 월급 입력 함수
void input(employee worker[], int num)
{
	printf("\n<직원직급,직원월급입력>\n");
	for (int i = 0; i < num; i++)                      //입력 받은 사원 수 만큼
	{
		printf("\n직원이름:%s\n", worker[i].name);
		do {
			printf("직원직급(1.사원 2.대리 3.과장):");
			scanf("%d", &worker[i].position);          //직급 입력 받기
		} while ((worker[i].position <= 0) || (worker[i].position > 3)); //범위에 맞지 않는 수 입력 시 다시 물어보기

		do {
			printf("직원월급(단위:만원):");
			scanf("%d", &worker[i].salary);            //월급 입력 받기
		} while (worker[i].salary < 0);                //범위에 맞지 않는 수 입력 시 다시 물어보기
	}
}


//직원의 이름, 직급, 월급 출력함수
void output(employee *worker, int num)
{
	printf("이름\t\t직급\t월급\t\n");
	for (int i = 0; i < num; i++)      //입력받은 사원수 만큼 반복
	{
		switch (worker[i].position)    //직급을 한글로 출력해주기 위해
		{
		case 1: //1 일때는 사원, 이름, 월급 출력
			printf("%s\t%s\t%d\n", worker[i].name, "사원", worker[i].salary);
			break;
		case 2: //2 일때는 대리, 이름, 월급 출력
			printf("%s\t%s\t%d\n", worker[i].name, "대리", worker[i].salary);
			break;
		case 3: //3 일때는 과장, 이름, 월급 출력
			printf("%s\t%s\t%d\n", worker[i].name, "과장", worker[i].salary);
			break;
		}
	}
}


//직급별 평균 월급 계산 및 출력 함수
float average(employee*worker, int position, int number)
{
	int count = 0, total = 0;                //차례로 직급별 인원수, 직급별 월급 총합 변수
	for (int i = 0; i < number; i++)         //입력받은 사원을 모두 검토한다
	{
		if (worker[i].position == position)  //그 중에서 입력한 position인수랑 같은 수를 갖는 사원들의
		{
			count += 1;                      //수를 세고
			total += worker[i].salary;       //그들의 월급을 모두 합한다
		}
	}
	return float(total) / count;             //평균(실수)을 돌려준다
}