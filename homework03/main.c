#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

char map[465]; /* 가로 30 + 1(개행문자) 세로 15 */

int writeStringToBuffer(const char* string, int x, int y);

void GotoXY(int x, int y);

void CursorView();


int print_loading()
{

	int i = 0;

		while(i < 465)
		{
			int x = i % 31;
			int y = i / 31;
	
			if(i == 0 || i == 29 || i == 434 || i == 463)
			{
				map[i] = '@';
			}
			else if(x == 30)
			{
				map[i] = '\n';
			}
			else if(x == 0 || x == 29)
			{
				map[i] = '|';
			}
			else if(y == 0 || y == 14)
			{
				map[i] = '-';
			}
			else
			{
				map[i] = ' ';
			}
			i++;		
		}	
		writeStringToBuffer("202327021", 11 , 14); 	
		writeStringToBuffer("Loading......", 9 , 7);

		map[464]='\0';	
}

int print_play()
{
		writeStringToBuffer("202327021", 11 , 14); 	
		writeStringToBuffer("Avoiding Lee Eunseok", 5 , 0);
		map[464]='\0';
}
int print_title()
{
	int i = 0;

		while(i < 465)
		{
			int x = i % 31;
			int y = i / 31;
	
			if(i == 0 || i == 29 || i == 434 || i == 463)
			{
				map[i] = '@';
			}
			else if(x == 30)
			{
				map[i] = '\n';
			}
			else if(x == 0 || x == 29)
			{
				map[i] = '|';
			}
			else if(y == 0 || y == 14)
			{
				map[i] = '-';
			}
			else
			{
				map[i] = ' ';
			}
			i++;		
		}
		
		writeStringToBuffer("202327021", 11 , 14);
		writeStringToBuffer("Avoiding Lee Eunseok", 5 , 0);
		writeStringToBuffer("Avoiding Lee Eunseok", 5 , 3);
		writeStringToBuffer("1. Start", 11 , 5);
		writeStringToBuffer("2. Help", 11 , 6);
		writeStringToBuffer("3. Exit", 11 , 7);

		map[464]='\0';	
}

int print_help()
{
	int i = 0;

		while(i < 465)
		{
			int x = i % 31;
			int y = i / 31;
	
			if(i == 0 || i == 29 || i == 434 || i == 463)
			{
				map[i] = '@';
			}
			else if(x == 30)
			{
				map[i] = '\n';
			}
			else if(x == 0 || x == 29)
			{
				map[i] = '|';
			}
			else if(y == 0 || y == 14)
			{
				map[i] = '-';
			}
			else
			{
				map[i] = ' ';
			}
			i++;
			
		}
		writeStringToBuffer("202327021", 11 , 14);
		writeStringToBuffer("Avoiding Lee Eunseok", 5 , 0);
		writeStringToBuffer("Help", 13 , 3);
		writeStringToBuffer("Press the space bar to jump!", 1 , 5);
		writeStringToBuffer("If you want to go back", 4 , 7);
		writeStringToBuffer("to the title screen", 5 , 8);
		writeStringToBuffer("please press 4", 8 , 9);
	
		map[464]='\0';
}

int print_exit()
{ 
	int i = 0;

		while(i < 465)
		{
			int x = i % 31;
			int y = i / 31;
	
			if(i == 0 || i == 29 || i == 434 || i == 463)
			{
				map[i] = '@';
			}
			else if(x == 30)
			{
				map[i] = '\n';
			}
			else if(x == 0 || x == 29)
			{
				map[i] = '|';
			}
			else if(y == 0 || y == 14)
			{
				map[i] = '-';
			}
			else
			{
				map[i] = ' ';
			}
			i++;
		}
		writeStringToBuffer("202327021", 11 , 14);
		writeStringToBuffer("Avoiding Lee Eunseok", 5 , 0);
		writeStringToBuffer("Exit", 13 , 3);
		writeStringToBuffer("Are you sure you want to", 3 , 5);
		writeStringToBuffer("exit the game?", 8 , 6);
		writeStringToBuffer("please press 0", 8, 7);
		
		map[464]='\0';
}

int main()
{
	system("cls");
	CursorView();
	int game_states = 4;
	while(game_states)
	{		
		if(game_states == 1)
		{
			print_loading();
			Sleep(3000);
			print_play();
			scanf("%d", &game_states);
		}
		else if(game_states == 2)
		{
			print_loading();
			Sleep(2000);
			print_help();
			scanf("%d", &game_states);
		}
		else if(game_states == 3)
		{
			print_exit();
			scanf("%d", &game_states);
		}
		else if(game_states == 4)
		{
			print_loading();
			Sleep(2000);
			print_title();
			scanf("%d", &game_states);
		}
		else if(game_states == 0)
		{
			exit(0);
		}
		else
		{
			print_loading();
			Sleep(2000);
			game_states = 4;
		}
	}
	return 0;
}
int writeStringToBuffer(const char* string, int x, int y)
{
	int i = 0;
	while(i < strlen(string))
	{
		
		map[i + x + 31 * y] = string[i];
		i++;
		Sleep(0);
		GotoXY(0, 0);	//go to xy
		printf("%s", map);
	}
}
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	//SetConsoleCursorPosition: 커서의 위치를 설정하는 함수입니다.
	//GetStdHandle(STD_OUTPUT_HANDLE): 표준 출력 핸들을 가져오는 함수입니다. 콘솔 화면에 대한 핸들을 반환합니다.
	//'Pos: COORD 구조체 변수로, 커서를 이동시킬 좌표를 나타냅니다. 
	//Pos.X는 커서의 가로 위치를, Pos.Y는 커서의 세로 위치를 나타냅니다.

}
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, }; //CONSOLE_CURSOR_INFO 구조체 변수인 cursorInfo를 선언하고 초기화하는 코드입니다.
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}