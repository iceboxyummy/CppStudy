#include "GameNode.h"

GameNode::GameNode()
{
}

GameNode::~GameNode()
{
}

void gotoxy(int x, int y)
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}