#include "Food.h"
#include "Snake.h"
#include "MainGame.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>

#define width 44
#define height 22

void PrintMap();
void CursorView();
void Start();
void End();

int main() {
	system("mode con: cols=44 lines=22");
	CursorView(); 
	PrintMap();
	Start();

	MainGame snakegame;

	snakegame.Init();

	while (snakegame.GetSnake()->IsDead() == false)
	{
		system("cls");

		PrintMap();

		snakegame.Update();

		snakegame.Render();

		Sleep(100);
	}
	
	End();

	system("cls");

	return 0;
}

void PrintMap()
{
	for (int x = 0; x < width; x += 2)
		std::cout << "※";
	std::cout << std::endl;

	for (int y = 1; y < height - 1; y++)
		for (int x = 0; x < width; x += 2)
			if (x == 0 || x == width - 2)
			{
				gotoxy(x / 2, y);
				std::cout << "※";
			}
	std::cout << std::endl;

	for (int x = 0; x < width; x += 2)
		std::cout << "※";
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Start()
{
	int start;

	gotoxy(9, 8);
	std::cout << "SNAKE GAME";
	gotoxy(3, 12);
	std::cout << ">>시작하려면 아무키나 누르세요<<";
	
	start = _getch();
}

void End() 
{
	int end;

	system("cls");

	PrintMap();

	gotoxy(9, 8);
	std::cout << "GAME END";
	gotoxy(3, 12);
	std::cout << ">>종료하려면 아무키나 누르세요<<";


	end = _getch();
}