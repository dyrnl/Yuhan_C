#include <stdio.h>

int main()
{
	int Game_state = 0;
	
	printf("연애 횟수를 입력하세요 : ");

	scanf("%d",&Game_state);

	if(Game_state)
	{
		printf("나는 연애%d번 해본 정상인임",Game_state);
	}
	else
	{
		printf("푸하하 꼴이 좋아?");
	}
	return 0;
}
