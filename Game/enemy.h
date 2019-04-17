#pragma once

#include "entity.h"
#include "random.h"

class enemy : public entity
{
public:
	float movementSpeed = 2.0;
	float movementLenght = 20;
	int attackDamage = 5;
	int counterWalking = 0;
	int direction = 0; // 1 - down, 2 - up, 3 - left, 4 - right
	int counterRoad;
	int hp = 5;
	bool alive = true;

	enemy();
	void update();
	void updateMovement();
};

