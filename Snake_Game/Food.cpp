#include "Food.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include"Snake.h"

Food::Food()
{
	srand(time(NULL));

	food_pos.x = rand() % 20 + 1;
	food_pos.y = rand() % 20 + 1;

	is_eaten = false;
}

Food::~Food()
{
}

void Food::SetIsEaten(bool is_eaten)
{
	this->is_eaten = is_eaten;
}

void Food::Init()
{
	is_eaten = false;

 	food_pos = { 10,11 };
}

void Food::Update()
{
}

void Food::Render()
{
	gotoxy(food_pos.x, food_pos.y);
	std::cout << "¡Ú";
}