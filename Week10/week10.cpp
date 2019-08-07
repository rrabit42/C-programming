#include <stdio.h>
#include <string.h>                     //string함수 라이브러리 불러오기

void name(void)                         //학생 인적사항 함수
{
	printf("====================\n");
	printf("====================\n");

}


int main(void)
{
	name();                            //인적사항 출력

	puts("<고향>\n\t\t\t정지용\n");                     //주어진 시 제목

	char sentense[][30] = { "고향에 고향에 돌아와도/",  //시 내용(2차원 문자열로 정의)
		"그리던 고향은 아니러뇨/",
		"산꿩이 알을 품고/",
		"뻐꾸기 제철에 울건만,/" };

	char final_S[100] = "";                             //2차원문자열인 시 내용을 1차원 문자열로 만들어서 담을 변수
	char text[100];                                     //사용자에게 입력받은 내용을 담을 문자열
	int i, j;                                           //반복문에 쓰일 변수들


	//시 내용을 1차원 문자열로 만들기
	for (int i = 0; i < (sizeof sentense) / 30; i++)    //문자열에 담긴 행의 수 만큼 반복
	{
		strcat(final_S, sentense[i]);                   //1차원 문자열로 만들기
	}


	//시 전체 출력
	for (int i = 0; i < strlen(final_S);i++)
	{
		putchar(final_S[i]);
		if (final_S[i] == '/')
			putchar('\n');                             //'/'만나면 줄바꿈해서 시 전체를 출력한다.
	}


	//사용자가 시 내용을 올바르게 쳤는지 확인하기
	puts("\n[타자연습]\n\n");

	   //한 줄씩 타자연습하게 하기
	for (i = 0, j = 0; i < strlen(final_S), j< sizeof sentense/30 ; i++)  //i를 이용해 1차원문자열 시 내용 한 줄로 끊고, j로는 원래 2차원문자열 시 내용 한 줄로 끊는다.
	{
		putchar(final_S[i]);                                              //시를 한글자씩 출력한다.

		if (final_S[i] == '/')                                            //한줄씩 출력하기 위해 '/'만나면
		{
			putchar('\n');                                                //다음줄로 넘어가

			gets_s(text);                                                 //사용자가 타자연습 한 문자열을 받는다
			strcat(text, "/");                                            //그 문자열에 /를 추가한다(비교하기 위함)

			if ( strcmp (sentense[j], text) == 0)                         //만약 시 내용과 사용자가 입력한 내용이 같으면
				puts("합격\n");                                           //합격
			else
				puts("불합격\n");                                         //아니면 불합격

			j++;                                                          //한줄 입력이 끝났을 시에만! j 조건 변화를 해준다.

		}

	}



}