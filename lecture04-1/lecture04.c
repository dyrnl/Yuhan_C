#include <stdio.h>

int main()
{
	int act;
	int enemyHP = 150;
	int myHP = 150;
	int heal = 50;
	int 몸통박치기 = 75;
	int 할퀴기 = 60;
	int 화염방사 = 100;


	printf("나의 턴 어떤 행동을 할 것인가요?\n1.공격 2.회복 3.도망\n");
	scanf("%c", &act);
	printf("",act);

	if(enemyHP==attack)
	{
	printf("주인공의 회심의 일격으로 %d의 데미지를 입혔습니다.\n\n",attack);
	printf("적의 남은 HP : %d\n\n",enemyHP-attack);
	printf("적을 처치하였습니다!\n\n캐리 ㅋ \n\n");
	}
	else if(enemyHP<attack)
	{
	printf("주인공의 회심의 일격으로 %d의 데미지를 입혔습니다.\n\n",attack);
	printf("적의 남은 HP 0\n\n");
	printf("적을 처치하였습니다!\n\n캐리 ㅋ \n\n");
	}
	else if(enemyHP>attack)
	{
	printf("주인공의 회심의 일격으로 %d의 데미지를 입혔습니다.\n\n",attack);
	printf("적의 남은 HP %d\n\n",enemyHP-attack);
	printf("적에게 당했습니다!\n\n아 팀차이 gg \n\n");
	}
}
