#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char map[465]; /* 가로 30 + 1(개행문자) 세로 15 */

int writeStringToBuffer(const char* string, int x, int y);

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
			writeStringToBuffer("202327021", 11 , 14); 				
		}

		writeStringToBuffer("Avoiding Lee Eunseok", 5 , 3);
		writeStringToBuffer("1. Start", 11 , 5);
		writeStringToBuffer("2. Help", 11 , 6);
		writeStringToBuffer("3. Exit", 11 , 7);

		map[464]='\0';	
		printf("%s", map);
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
			writeStringToBuffer("202327021", 11 , 14);
		}

		writeStringToBuffer("Help", 13 , 3);
		writeStringToBuffer("Press the space bar to jump!", 1 , 5);
		writeStringToBuffer("If you want to go back", 4 , 7);
		writeStringToBuffer("to the title screen", 5 , 8);
		writeStringToBuffer("please press 4", 8 , 9);
	
		map[464]='\0';	
		printf("%s", map);
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
			writeStringToBuffer("202327021", 11 , 14);
		}
		writeStringToBuffer("Exit", 13 , 3);
		writeStringToBuffer("Are you sure you want to", 3 , 5);
		writeStringToBuffer("exit the game?", 8 , 6);
		writeStringToBuffer("please press 0", 8, 7);
		
		map[464]='\0';
		printf("%s", map);
}

int main()
{
	int game_states = 4;
	while(game_states)
	{		
		if(game_states == 1)
		{
			system("cls");
			print_title();
			scanf("%d", &game_states);
		}
		else if(game_states == 2)
		{
			system("cls");
			print_help();
			scanf("%d", &game_states);
		}
		else if(game_states == 3)
		{
			system("cls");
			print_exit();
			scanf("%d", &game_states);
		}
		else if(game_states == 4)
		{
			system("cls");
			print_title();
			scanf("%d", &game_states);
		}
		else if(game_states == 0)
		{
			exit(0);
			system("cls");
		}
		else
		{
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
	}
}
