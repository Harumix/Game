#include "player.h"

player::player()
{
	rect.setSize(sf::Vector2f(250, 250));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Cyan);
	sprite.setTextureRect(sf::IntRect(128, 128, 64, 64));
	sprite.setScale(sf::Vector2f(4, 8));
}

void player::update()
{
	sprite.setPosition(rect.getPosition());
}

void player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rect.move(-movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 64, 64, 64));
		direction = 3;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rect.move(movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 192, 64, 64));
		direction = 4;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 0, 64, 64));
		direction = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		rect.move(0, movementSpeed);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 128, 64, 64));
		direction = 1;
	}

	counterWalking++;

	if (counterWalking == 9) {
		counterWalking = 0;
	}
}
