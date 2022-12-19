#pragma once
#include<windows.h>

class GameNode
{
public:
	GameNode();
	virtual ~GameNode();

	virtual void Init() = 0;
	virtual void Update() {}
	virtual void Render() = 0;
};

void gotoxy(int x, int y);

struct Pos
{
	int x;
	int y;
};