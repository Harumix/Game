#pragma once

#include "entity.h"
#include "random.h"

class enemy : public entity
{
public:
	float movementSpeed = 0.05;
	float movementLenght = 2000;
	int attackDamage = 5;
	int counterWalking = 0;
	int direction = 0; // 1 - down, 2 - up, 3 - left, 4 - right
	int counterRoad;

	enemy();
	void update();
	void updateMovement();
};

