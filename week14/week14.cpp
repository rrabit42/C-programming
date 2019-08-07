#include<stdio.h>        //기본함수 라이브러리
#include <stdlib.h>      //exit쓰기 위한 라이브러리
#include <string.h>      //문자열함수 라이브러리

//학생 정보 매크로
#define NAME printf("======================\n");\
	printf("======================\n");\

int main(void)
{
	NAME; //학생 정보 출력

	char name[50];        //강아지 이름 받을 배열
	char dog[50];         //강아지 품종 받을 배열
	int num[50];          //강아지 나이 받을 배열
	int *nump = num;      //강아지 나이 변수 가리킬 포인터
	int age;              //파일에서 강아지 나이 스캔받을 변수
	FILE *fp, *dp;        //파일 가리키는 포인터

	fp = fopen("d:\\output.txt", "a");                        //파일을 a형식으로 연다(파일이 없으면 만든다)
	if (fp == NULL) { printf("파일열기 실패\n"); exit(1); }   //파일이 열리지 않아 읽을 수 없는 경우 main에 1 리턴하고 프로그램 종료
	
	//사용자에게 강아지 정보 입력받기
	printf("강아지 이름, 종, 나이를 차례로 입력하세요<종료시 이름에 \"0\"입력>\n");
	while (1)
	{
		//이름 입력받기
		printf("\n이름:");
		gets_s(name);
		if (strcmp(name,"0")==0) break; //만약 0이 입력되면 무한루프 탈출

		//견종 입력받기
		printf("견종:");
		gets_s(dog);

		//나이 입력받기
		printf("나이:");
		scanf("%d", num);

		//입력받은 이름,견종,나이 파일에 저장
		fprintf(fp, "\n%s\t%s\t%\d", name, dog, *num);

		//버퍼에 남겨진 엔터 빼기
		getchar();
	}
	fclose(fp); //a형식으로 열었던 파일 닫기


	//3살 이하 강아지들 출력하기
	dp = fopen("d:\\output.txt", "r");                       //r형식으로 방금 만든 파일 열기
	if (dp == NULL) { printf("파일열기 실패\n"); exit(1); }  //파일이 열리지 않아 읽을 수 없는 경우 main에 1 리턴하고 프로그램 종료

	printf("\n나이가 3세 이하인 강아지\n");
	printf("\n이름\t견종\t나이\t\n");
	for(;;)
	{
		fscanf(dp, "%s\t%s\t%d", &name,&dog,&age);           //파일에서 각각 이름,견종,나이 스캔받기
		if (age <= 3)                                        //3살 이하인 강아지의 경우에만
		{
			printf("%s\t%s\t%d",name,dog,age);               //프로그램 화면에 출력하기
		}
		
		if (feof(dp)) break;                                 //만약 파일의 마지막에 다다르면 무한루프 탈출
	}

	fclose(dp);                                              //a형식으로 열었던 파일을 닫는다

	return 0;  //정상적으로 작동되었으므로 0 리턴
}