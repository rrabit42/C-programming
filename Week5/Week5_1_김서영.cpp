#include <stdio.h>
int main(void)
{
//사용자로부터 입력받을 미세먼지 지수 변수 지정
	int dust;

//입력창 문구 작성
	printf("<미세먼지 측정>\n");
	printf("미세먼지 지수를 입력해주세요:");

//사용자로부터 미세먼지 지수 입력받기
	scanf("%d", &dust);

//결과창 출력을 위해 미세먼지 지수 범위 조건문 작성 및 결과창 출력
	if (dust < 0)
		printf("잘못입력하셨습니다.\n"); //0미만을 입력받았을 경우
	else
	{
		if (dust >= 0 && dust <= 30) printf("미세먼지: 좋음\n");
		else if (dust <= 80) printf("미세먼지: 보통\n");
		else if (dust <= 150) printf("미세먼지: 나쁨\n");
		else printf("미세먼지: 매우나쁨\n"); 
	}
	

}