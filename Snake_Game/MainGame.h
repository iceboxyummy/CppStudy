#pragma once
#include "GameNode.h"

class MainGame final : public GameNode
{
public:
	MainGame();
	~MainGame();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	class Snake* GetSnake();
	class Food* GetFood();

private:
	class Snake* pSnake;
	class Food* pFood;
};