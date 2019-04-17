#pragma once

#include "entity.h"

class projectile : public entity
{
public:
	float movementSpeedBullet = 20.0;
	int attackDamage = 5;
	int direction = 0; // 1 - down, 2 - up, 3 - left, 4 - right
	bool destroy = false;
	int road = 0;
	int lifeTime = 25;

	projectile();
	void update();
};


