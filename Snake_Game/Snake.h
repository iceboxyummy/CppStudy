#pragma 

#include "GameNode.h"
#include <vector>

enum class Dir {
	up = 'w', down = 's', left = 'a', right = 'd',
	UP = 'W', DOWN = 'S', LEFT = 'A', RIGHT = 'D'
};

class Snake final : public GameNode
{
public:
	Snake();
	~Snake();

	void FollowHead();
	void MoveHead();
	void IsCollision();
	void IsEat(class Food& food);
	void AddBody();
	const bool& IsDead() const { return is_dead; }
	void SetDir();

	virtual void Init() override;
	virtual void Update(Food& food);
	virtual void Render() override;

private:
	bool is_eat;
	bool is_dead;
	std::vector<Pos> snake;
	int size;
	Dir dir;
};