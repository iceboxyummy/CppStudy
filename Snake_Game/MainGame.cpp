#include "MainGame.h"
#include "Food.h"
#include "Snake.h"

MainGame::MainGame()
{
	pSnake = new Snake;
	pFood = new Food;
}

MainGame::~MainGame()
{
	if (pSnake)
	{
		delete pSnake;
		pSnake = nullptr;
	}

	if (pFood)
	{
		delete pFood;
		pFood = nullptr;
	}
}

void MainGame::Init()
{
	if (pSnake != nullptr)
		pSnake->Init();

	if (pFood != nullptr)
		pFood->Init();
}

void MainGame::Update()
{
	if (pSnake != nullptr)
		pSnake->Update(*pFood);

	if (pFood != nullptr)
		if (pFood->GetIsEaten() == true)
		{
			delete pFood;
			pFood = nullptr;
		}

	if (pFood == nullptr)
		pFood = new Food;
}

void MainGame::Render()
{
	if (pFood != nullptr)
		pFood->Render();

	if (pSnake != nullptr)
		pSnake->Render();

}

Snake* MainGame::GetSnake() { return pSnake; }

Food* MainGame::GetFood() { return pFood; }