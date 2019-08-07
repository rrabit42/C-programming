#include <stdio.h>
int main(void)
{

//사용자한테 입력받을 '월' 변수 지정
	int month;

//사용자에게 정수 입력받기
	printf("Choose the month you like.\n");
	scanf("%d", &month);

//사용자에게 입력받은 '월'을 이용해 좋아하는 계절이 무엇인지 알려준다.
	switch(month)
	{
	case 3:
	case 4:
	case 5:
		printf("You like spring\n"); //3,4,5월은 spring
		break;
	case 6:
	case 7:
	case 8:
		printf("You like summer\n"); //6,7,8월은 summer
		break;
	case 9:
	case 10:
	case 11:
		printf("You like fall\n");  //9,10,11월은 fall
		break;
	case 12:
	case 1:
	case 2:
		printf("You like winter\n");//12,1,2월은 winter
		break;
	default:
		printf("Wrong input\n");    //열 두달이 아닌 다른 정수를 입력한 경우는 잘못된 입력이라고 출력
		break;
	}

}
