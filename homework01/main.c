#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int print_title()
{
	char map[465]; /* 가로 30 + 1(개행문자) 세로 15 */
	int z = 0;

		while(z < 465)
		{
			int x = z % 31;
			int y = z / 31;
	
			if(z == 0 || z == 29 || z == 434 || z == 463)
			{
				map[z] = '@';
			}
			else if(x == 30)
			{
				map[z] = '\n';
			}
			else if(x == 0 || x == 29)
			{
				map[z] = '|';
			}
			else if(y == 0 || y == 14)
			{
				map[z] = '-';
			}
			else
			{
				map[z] = ' ';
			}
			z++;
				

		}
		char msg[10] = "202327021";
		int a = 0;
		while(a < strlen(msg))
		{
			map[a + ((30 / 2) - (strlen(msg) / 2)) + 31 * 14] = msg[a];
			a++;
		}
		int b = 0;
		char msg1[10] = "Dino Game";
		while(b < strlen(msg1))
		{
			map[b + ((30 / 2) - (strlen(msg1) / 2)) + 31 * 3] = msg1[b];
			b++;
		}
		int c = 0;
		char msg2[9] = "1. Start";
		while(c < strlen(msg2))
		{
			map[c + ((30 / 2) - (strlen(msg2) / 2)) + 31 * 5] = msg2[c];
			c++;
		}
		int d = 0;
		char msg3[9] = "2. Help";
		while(d < strlen(msg3))
		{
			map[d + ((30 / 2) - (strlen(msg3) / 2)) + 31 * 6] = msg3[d];
			d++;
		}
		int e = 0;
		char msg4[9] = "3. Exit";
		while(e < strlen(msg4))
		{
			map[e + ((30 / 2) - (strlen(msg4) / 2)) + 31 * 7] = msg4[e];
			e++;
		}
		map[464]='\0';	
		printf("%s", map);
}

int print_help()
{
	char map[465]; /* 가로 30 + 1(개행문자) 세로 15 */
	int z = 0;

	while(z < 465)
		{
			int x = z % 31;
			int y = z / 31;
	
			if(z == 0 || z == 29 || z == 434 || z == 463)
			{
				map[z] = '@';
			}
			else if(x == 30)
			{
				map[z] = '\n';
			}
			else if(x == 0 || x == 29)
			{
				map[z] = '|';
			}
			else if(y == 0 || y == 14)
			{
				map[z] = '-';
			}
			else
			{
				map[z] = ' ';
			}
			z++;	

		}
	
		char msg[10] = "202327021";
		int a = 0;
		while(a < strlen(msg))
		{
			map[a + ((30 / 2) - (strlen(msg) / 2)) + 31 * 14] = msg[a];
			a++;
		}
		int f = 0;
		char msg5[5] = "Help";
		while(f < strlen(msg5))
		{
			map[f + ((30 / 2) - (strlen(msg5) / 2)) + 31 * 3] = msg5[f];
			f++;
		}
		int g = 0;
		char msg6[28] = "Press the space bar to jump";
		while(g < strlen(msg6))
		{
			map[g + ((30 / 2) - (strlen(msg6) / 2)) + 31 * 5] = msg6[g];
			g++;
		}
		int h = 0;
		char msg7[23] = "If you want to go back";
		while(h < strlen(msg7))
		{
			map[h + ((30 / 2) - (strlen(msg7) / 2)) + 31 * 7] = msg7[h];
			h++;
		}
		int i = 0;
		char msg8[20] = "to the title screen";
		while(i < strlen(msg8))
		{
			map[i + ((30 / 2) - (strlen(msg8) / 2)) + 31 * 8] = msg8[i];
			i++;	
		}
		int j = 0;
		char msg9[15] = "please press 4";
		while(j < strlen(msg9))
		{
			map[j + ((30 / 2) - (strlen(msg9) / 2)) + 31 * 9] = msg9[j];
			j++;	
		}
		map[464]='\0';	
		printf("%s", map);
}
int print_exit()
{ 
	char map[465]; /* 가로 30 + 1(개행문자) 세로 15 */
	int z = 0;

		while(z < 465)
		{
			int x = z % 31;
			int y = z / 31;
	
			if(z == 0 || z == 29 || z == 434 || z == 463)
			{
				map[z] = '@';
			}
			else if(x == 30)
			{
				map[z] = '\n';
			}
			else if(x == 0 || x == 29)
			{
				map[z] = '|';
			}
			else if(y == 0 || y == 14)
			{
				map[z] = '-';
			}
			else
			{
				map[z] = ' ';
			}
			z++;
				

		}
		char msg[10] = "202327021";
		int a = 0;
		while(a < strlen(msg))
		{
			map[a + ((30 / 2) - (strlen(msg) / 2)) + 31 * 14] = msg[a];
			a++;
		}
		int k = 0;
		char msg10[5] = "Exit";
		while(k < strlen(msg10))
		{
			map[k + ((30 / 2) - (strlen(msg10) / 2)) + 31 * 3] = msg10[k];
			k++;
		}
		int l = 0;
		char msg11[25] = "Are you sure you want to";
		while(l < strlen(msg11))
		{
			map[l + ((30 / 2) - (strlen(msg11) / 2)) + 31 * 5] = msg11[l];
			l++;
		}
		int m = 0;
		char msg12[15] = "exit the game?";
		while(m < strlen(msg12))
		{
			map[m + ((30 / 2) - (strlen(msg12) / 2)) + 31 * 6] = msg12[m];
			m++;
		}
		int n = 0;
		char msg13[15] = "please press 0";
		while(n < strlen(msg13))
		{
			map[n + ((30 / 2) - (strlen(msg13) / 2)) + 31 * 7] = msg13[n];
			n++;
		}
		map[464]='\0';
		printf("%s", map);
}

int main()
{
	int game_states = 4;
	while(game_states)
	{		
		if(game_states == 4)
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
		else if(game_states == 0)
		{
			exit(0);
			system("cls");
		}
		else
		{
			game_states = 1;
		}
	}
	return 0;
}

