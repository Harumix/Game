#include "enemy.h"

enemy::enemy()
{
	rect.setSize(sf::Vector2f(50, 128));
	rect.setPosition(500, 158);
	rect.setFillColor(sf::Color::Cyan);
	sprite.setTextureRect(sf::IntRect(128, 128, 64, 64));
	sprite.setScale(sf::Vector2f(2, 1));
}

void enemy::update()
{
	sprite.setPosition(rect.getPosition().x-40,rect.getPosition().y);
}

void enemy::updateMovement()
{
	if (direction == 3)
	{
		rect.move(-movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 64, 64, 64));
	}

	else if (direction == 4)
	{
		rect.move(movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 192, 64, 64));
	}

	/*
	else if (direction == 2)
	{
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 0, 64, 64));
	}

	else if (direction == 1)
	{
		rect.move(0, movementSpeed);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 128, 64, 64));
	}*/
	else 
	{
		// MAGIA NIC TU NIE
	}

	counterWalking++;
	if (counterWalking == 9) {
		counterWalking = 0;
	}

	counterRoad++;
	if (counterRoad >= movementLenght)
	{
		direction = generateRandom(8);
		counterRoad = 0;
	}
}
