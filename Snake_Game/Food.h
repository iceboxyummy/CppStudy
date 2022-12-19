#pragma once
#include "GameNode.h"

class Food final : public GameNode
{
public:
	Food();
	~Food();

	const int& GetFoodPosX() const { return food_pos.x; }
	const int& GetFoodPosY() const { return food_pos.y; }
	void SetIsEaten(bool is_eaten);
	const bool GetIsEaten() const { return is_eaten; }

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	bool is_eaten;
	Pos food_pos;
};