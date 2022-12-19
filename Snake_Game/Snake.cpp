#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>
#include "Food.h"

Snake::Snake()
{
}

Snake::~Snake()
{
}

void Snake::FollowHead()
{
	for (int i = size - 1; i > 0; i--)
	{
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
}

void Snake::MoveHead()
{
	FollowHead();

	switch (dir)
	{
	case Dir::UP:
		snake[0].y -= 1;
		break;

	case Dir::LEFT:
		snake[0].x -= 1;
		break;

	case Dir::RIGHT:
		snake[0].x += 1;
		break;

	case Dir::DOWN:
		snake[0].y += 1;
		break;
	}
}

void Snake::SetDir()
{
	char input = '\0';

	if (_kbhit())
	{
		input = _getch();

		switch (input)
		{
		case 'W':
		case 'w':
			dir = Dir::UP;
			break;

		case 'A':
		case 'a':
			dir = Dir::LEFT;
			break;

		case 'S':
		case 's':
			dir = Dir::DOWN;
			break;

		case 'D':
		case 'd':
			dir = Dir::RIGHT;
			break;
		}
	}
}
void Snake::IsCollision()
{
	if (snake[0].x < 1 || snake[0].x > 20 || snake[0].y < 1 || snake[0].y > 20) // 벽과 출돌
		is_dead = true;
	else
		is_dead = false;

	for (int i = 1; i < size; i++)
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) // 몸통과 충돌
			is_dead = true;
}

void Snake::IsEat(Food& food)
{
	if (snake[0].x == food.GetFoodPosX() && snake[0].y == food.GetFoodPosY())
	{
		is_eat = true;
		food.SetIsEaten(true);
	}
}

void Snake::AddBody()
{
	if (is_eat == true)
	{
		if (snake[size - 1].x > snake[size - 2].x)
			snake.push_back(Pos{ snake[size - 1].x + 1, snake[size - 1].y });
		else if (snake[size - 1].x < snake[size - 2].x)
			snake.push_back(Pos{ snake[size - 1].x - 1, snake[size - 1].y });
		else if (snake[size - 1].y < snake[size - 2].y)
			snake.push_back(Pos{ snake[size - 1].x, snake[size - 1].y - 1 });
		else if (snake[size - 1].y > snake[size - 2].y)
			snake.push_back(Pos{ snake[size - 1].x, snake[size - 1].y + 1 });

		size++;

		is_eat = false;
	}
}

void Snake::Init()
{
	is_eat = false;
	is_dead = false;
	snake.reserve(100);
	snake.push_back(Pos{ 5,11 });
	snake.push_back(Pos{ 4,11 });
	snake.push_back(Pos{ 3,11 });
	size = 3;
	dir = Dir::RIGHT;
}

void Snake::Update(Food& food)
{
	time_t pre_time;
	time_t cur_time;

	pre_time = clock();

	while (1)
	{
		cur_time = clock();
		time_t time = cur_time - pre_time;
		SetDir();
		if (time > 100) 
			break;
	}
	MoveHead();
	IsEat(food);
	IsCollision();
	AddBody();
}

void Snake::Render()
{
	for (int i = size - 1; i >= 0; i--)
	{
		gotoxy(snake[i].x, snake[i].y);

		if (i == 0)
		{
			std::cout << "◆" << std::endl;
		}
		else
			std::cout << "■" << std::endl;
	}
}