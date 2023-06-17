#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#define MAX_PROJECTILES 4

char map[496]; /* ���� 30 + 1(���๮��) ���� 15 */

int writeStringToBuffer(const char* string, int x, int y);

int Buffernotsleep(const char* string, int x, int y);

void mapBuffer();

void GotoXY(int x, int y);

void CursorView();

int score = 0;

void print_play()
{
	mapBuffer();

	GotoXY(0, 0);
}

void game_over()
{
	mapBuffer();

	writeStringToBuffer("GameOver", 11, 3);
	writeStringToBuffer("Press 1 to start again", 4, 7);
	writeStringToBuffer("or", 14, 8);
	writeStringToBuffer("Press 0 to end the game", 4, 9);
	GotoXY(8, 5);
	printf("\033[34mFinal Score: %d\033[0m\n", score);

	GotoXY(0, 0);
	score = 0;
}

int move_charandscoreandprojectile()
{
	//���ӽ��� �� ��ġ ����
	int playerX = 14;
	int playerY = 7;

	//�̵��ӵ� ����
	const int frameTime = 1000 / 20;

	ULONGLONG currentTick = GetTickCount64();
	ULONGLONG lastTick = currentTick;


	struct Projectile
	{
		int x;
		int y;
		int dx;
		int dy;
	};
	struct Projectile2
	{
		int x;
		int y;
		int dx;
		int dy;
	};
	struct Projectile3
	{
		int x;
		int y;
		int dx;
		int dy;
	};
	struct Projectile4
	{
		int x;
		int y;
		int dx;
		int dy;
	};
	struct Projectile projectile = { 0, 0, 0, 0 };
	struct Projectile2 projectile2 = { 0, 0, 0, 0 };
	struct Projectile3 projectile3 = { 0, 0, 0, 0 };
	struct Projectile4 projectile4 = { 0, 0, 0, 0 };

	srand(time(NULL)); // ���� �õ� �ʱ�ȭ

	time_t startTime = time(NULL); // ���� �ð��� �����ɴϴ�.
	while (1)
	{
		// Input
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) { // ����
			if (playerX > 1)
				playerX = playerX - 1;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { // ������
			if (playerX + 1 < 29)
				playerX = playerX + 1;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) { // ��
			if (playerY > 1)
				playerY = playerY - 1;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) { // �Ʒ�
			if (playerY + 1 < 14)
				playerY = playerY + 1;
		}
		time_t currentTime = time(NULL); // ���� �ð��� �����ɴϴ�.

		if (currentTime - startTime >= 1) { // 1�ʰ� ������� ��
			score++; // ������ 1 ������ŵ�ϴ�.
			startTime = currentTime; // ���� �ð��� ������Ʈ�մϴ�.
		}
		// ���� ���� �� ��ġ ����
		if (projectile.x == 0 && projectile.y == 0)
		{
			projectile.x = rand() % 29;
			projectile.y = 14;
			projectile.dx = 0;
			projectile.dy = -1;
		}
		if (projectile2.x == 0 && projectile2.y == 0)
		{
			projectile2.x = rand() % 29;
			projectile2.y = 1;
			projectile2.dx = 0;
			projectile2.dy = 1;
		}
		if (projectile3.x == 0 && projectile3.y == 0)
		{
			projectile3.x = 1;
			projectile3.y = rand() % 14;
			projectile3.dx = 1;
			projectile3.dy = 0;
		}
		if (projectile4.x == 0 && projectile4.y == 0)
		{
			projectile4.x = 29;
			projectile4.y = rand() % 14;
			projectile4.dx = -1;
			projectile4.dy = 0;
		}

		//�׵θ� ����� �� ó��
		if (projectile.y == 0)
		{
			projectile.x = 0;
			projectile.y = 0;
			projectile.dx = 0;
			projectile.dy = 0;
		}
		if (projectile2.y == 14)
		{
			projectile2.x = 0;
			projectile2.y = 0;
			projectile2.dx = 0;
			projectile2.dy = 0;
		}
		if (projectile3.x == 29)
		{
			projectile3.x = 0;
			projectile3.y = 0;
			projectile3.dx = 0;
			projectile3.dy = 0;
		}
		if (projectile4.x == 0)
		{
			projectile4.x = 0;
			projectile4.y = 0;
			projectile4.dx = 0;
			projectile4.dy = 0;
		}
		// ����ü ������Ʈ
		projectile.x += projectile.dx;
		projectile.y += projectile.dy;

		projectile2.x += projectile2.dx;
		projectile2.y += projectile2.dy;

		projectile3.x += projectile3.dx;
		projectile3.y += projectile3.dy;

		projectile4.x += projectile4.dx;
		projectile4.y += projectile4.dy;

		if (projectile.x < 1)
		{
			projectile.x = 1;
		}
		else if (projectile.x > 29)
		{
			projectile.x = 29;
		}

		if (projectile2.x < 1)
		{
			projectile2.x = 1;
		}
		else if (projectile2.x > 29)
		{
			projectile2.x = 29;
		}
		if (projectile3.y < 1)
		{
			projectile3.y = 1;
		}
		else if (projectile3.y > 14)
		{
			projectile3.y = 14;
		}
		if (projectile4.y < 1)
		{
			projectile4.y = 1;
		}
		else if (projectile4.y > 14)
		{
			projectile4.y = 14;
		}

		// Rendering

		GotoXY(0, 0);
		printf("%s", map);
		//ĳ���� ���
		GotoXY(playerX, playerY);
		printf("��");
		//���� ���
		GotoXY(18, 15);
		printf("Score : %d", score);

		// ����ü ���
		GotoXY(projectile.x, projectile.y);
		printf("��");

		GotoXY(projectile2.x, projectile2.y);
		printf("��");

		GotoXY(projectile3.x, projectile3.y);
		printf("��");

		GotoXY(projectile4.x, projectile4.y);
		printf("��");

		// �浹 üũ
		if (playerX == projectile.x && playerY == projectile.y || playerX == projectile2.x && playerY == projectile2.y || 
			playerX == projectile3.x && playerY == projectile3.y || playerX == projectile4.x && playerY == projectile4.y)
		{
			system("cls");// �浹 �� ���� ����
			break;
		}

		// ����ü�� ȭ�� ����� �����
		if (projectile.x < 1 || projectile.x > 29 || projectile.y < 1 || projectile.y > 14)
		{
			projectile.x = rand() % 29;
			projectile.y = 14;
			projectile.dx = 0;
			projectile.dy = -1;
		}
		if (projectile2.x < 1 || projectile2.x > 29 || projectile2.y < 1 || projectile2.y > 14)
		{
			projectile2.x = rand() % 29;
			projectile2.y = 1;
			projectile2.dx = 0;
			projectile2.dy = 1;
		}
		if (projectile3.x < 1 || projectile3.x > 29 || projectile3.y < 1 || projectile3.y > 14)
		{
			projectile3.x = 1;
			projectile3.y = rand() % 14;
			projectile3.dx = 1;
			projectile3.dy = 0;
		}
		if (projectile4.x < 1 || projectile4.x > 29 || projectile4.y < 1 || projectile4.y > 14)
		{
			projectile4.x = 29;
			projectile4.y = rand() % 14;
			projectile4.dx = -1;
			projectile4.dy = 0;
		}

		// Frame rate control
		currentTick = GetTickCount64();
		ULONGLONG elapsedTick = currentTick - lastTick;
		if (elapsedTick < frameTime) 
		{
			Sleep(frameTime - elapsedTick);
		}
		lastTick = currentTick;
	}
	return 0;
}

void print_loading()
{
	mapBuffer();
	writeStringToBuffer("Loading......", 9, 7);
}

void print_title()
{
	mapBuffer();
	Buffernotsleep("202327021", 11, 14);
	writeStringToBuffer("Avoiding", 11, 3);
	writeStringToBuffer("1. Start", 11, 5);
	writeStringToBuffer("2. Help", 11, 6);
	writeStringToBuffer("3. Exit", 11, 7);
}

void print_help()
{
	mapBuffer();
	Buffernotsleep("Avoiding", 11, 0);
	writeStringToBuffer("Help", 13, 3);
	writeStringToBuffer("Press the rudder keys", 4, 5);
	writeStringToBuffer("to move the character!", 4, 6);
	writeStringToBuffer("If you want to go back", 4, 8);
	writeStringToBuffer("to the title screen", 5, 9);
	writeStringToBuffer("please press 4", 8, 10);
}

void print_exit()
{
	mapBuffer();
	Buffernotsleep("Avoiding", 11, 0);
	writeStringToBuffer("Exit", 13, 3);
	writeStringToBuffer("Are you sure you want to", 3, 5);
	writeStringToBuffer("exit the game?", 8, 6);
	writeStringToBuffer("please press 0", 8, 7);
}

int main()
{
	CursorView();
	int game_states = 4;

	while (game_states)
	{
		if (game_states == 1)
		{
			system("cls");
			print_loading();
			Sleep(3000);
			print_play();
			move_charandscoreandprojectile();
			game_over();

			scanf_s("%d", &game_states);
		}
		else if (game_states == 2)
		{
			print_loading();
			Sleep(2000);
			print_help();
			scanf_s("%d", &game_states);
		}
		else if (game_states == 3)
		{
			print_exit();
			scanf_s("%d", &game_states);
		}
		else if (game_states == 4)
		{
			print_loading();
			Sleep(2000);
			print_title();
			scanf_s("%d", &game_states);
		}
		else if (game_states == 0)
		{
			exit(0);
		}
		else
		{
			writeStringToBuffer("Invalid input.", 8, 12);
			writeStringToBuffer("Please input it again.", 4, 13);
			scanf_s("%d", &game_states);
		}
	}
	return 0;
}

int Buffernotsleep(const char* string, int x, int y)
{
	for (int i = 0; i < strlen(string);)
	{
		map[i + x + 31 * y] = string[i];
		i++;
		GotoXY(0, 0);	//go to xy
		printf("%s", map);
	}
	return 0;
}

int writeStringToBuffer(const char* string, int x, int y)
{
	for (int i = 0;i < strlen(string);)
	{
		map[i + x + 31 * y] = string[i];
		i++;
		Sleep(30);
		GotoXY(0, 0);	//go to xy
		printf("%s", map);
	}
	return 0;
}

void mapBuffer()
{
	int i = 0;

	while (i < 465)
	{
		int x = i % 31;
		int y = i / 31;

		if (i == 0 || i == 29 || i == 434 || i == 463)
		{
			map[i] = '+';
		}
		else if (x == 30)
		{
			map[i] = '\n';
		}
		else if (x == 0 || x == 29)
		{
			map[i] = '|';
		}
		else if (y == 0 || y == 14)
		{
			map[i] = '-';
		}
		else
		{
			map[i] = ' ';
		}
		i++;
	}
	map[495] = '\0';
}
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	//SetConsoleCursorPosition: Ŀ���� ��ġ�� �����ϴ� �Լ��Դϴ�.
	//GetStdHandle(STD_OUTPUT_HANDLE): ǥ�� ��� �ڵ��� �������� �Լ��Դϴ�. �ܼ� ȭ�鿡 ���� �ڵ��� ��ȯ�մϴ�.
	//'Pos: COORD ����ü ������, Ŀ���� �̵���ų ��ǥ�� ��Ÿ���ϴ�. 
	//Pos.X�� Ŀ���� ���� ��ġ��, Pos.Y�� Ŀ���� ���� ��ġ�� ��Ÿ���ϴ�.
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, }; //CONSOLE_CURSOR_INFO ����ü ������ cursorInfo�� �����ϰ� �ʱ�ȭ�ϴ� �ڵ��Դϴ�.
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}