#pragma once

#include "entity.h"

class player: public entity
{
public:
	float movementSpeed = 0.1;
	int attackDamage = 5;
	int counterWalking = 0;
	int direction = 0; // 1 - down, 2 - up, 3 - left, 4 - right

	player();
	void update();
	void updateMovement();
};


