#include "projectile.h"

projectile::projectile() 
{
	rect.setSize(sf::Vector2f(25, 25));
	rect.setFillColor(sf::Color::Green);
	//sprite.setTextureRect(sf::IntRect(128, 128, 64, 64));
}

void projectile::update()
{
	if (direction == 1)
	{
		rect.move(0, movementSpeedBullet);
	}

	if (direction == 2)
	{
		rect.move(0, -movementSpeedBullet);
	}

	if (direction == 3)
	{
		rect.move(-movementSpeedBullet, 0);
	}

	if (direction == 4)
	{
		rect.move(movementSpeedBullet, 0);
	}
	
	road++;
	if (road >= lifeTime) {
		destroy = true;
	}
}

