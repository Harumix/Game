#pragma once

#include "entity.h"

class projectile : public entity
{
public:
	float movementSpeedBullet = 5.0;
	int attackDamage = 50;
	int direction = 0; // 1 - down, 2 - up, 3 - left, 4 - right
	bool destroy = false;
	int road = 10;
	int lifeTime = 40;

	projectile();
	void update();
};


