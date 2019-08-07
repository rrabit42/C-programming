#include <stdio.h>
#include <string.h>  //문자열 관련함수 헤더파일

//학생 정보 함수
void NAME()
{
	printf("===================\n");
	printf("===================\n");
}


int main()
{
	NAME();               //학생 정보 출력

	char string1[100];    //처음 입력받을 문자열
	char string2[100];    //변환 후 문자열
	char ini;             //문자 한 개 변수
	int length;           //문자열 길이 변수


	//사용자로부터 문자열 입력받기
	printf("문자열을 입력하세요.\n");
	gets_s(string1);
	length = strlen(string1);              //문자열의 길이 계산

	for (int i = 0; i < length ;i++)       //문자열 길이만큼 반복해서 문자 한개씩 살펴보기
	{
		ini = string1[i];                  //ini는 문자 1개
		if (ini >= 'A' && ini <= 'Z')      //ini가 대문자이면
			ini = ini + 32;                //소문자로 변환(아스키코드 이용)
		else if (ini >= 'a' && ini <= 'z') //ini가 소문자이면
			ini = ini - 32;                //대문자로 변환

		string2[i] = ini;                  //string2에 차례로 변환된 문자들 대입
	}

	string2[length] = '\0';                //문자열의 마지막은 null로 닫아준다


	//결과 출력
	printf("변경 전 문자열:%s\n", string1);   //처음 문자열
	printf("변경 후 문자열:%s\n", string2);   //변환 후 문자열
}