#pragma once

#include "entity.h"

class projectile : public entity
{
public:
	float movementSpeedBullet = 0.5;
	int attackDamage = 5;
	int direction = 0; // 1 - down, 2 - up, 3 - left, 4 - right

	projectile();
	void update();
};


