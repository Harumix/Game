#include "player.h"

sf::Clock zegar;

player::player()
{
	rect.setSize(sf::Vector2f(50, 100));
	rect.setPosition(0, 125);
	rect.setFillColor(sf::Color::Cyan);
	sprite.setTextureRect(sf::IntRect(22, 149, 65, 90));
	sprite.setScale(sf::Vector2f(1, 1));
}

void player::update()
{
	sprite.setPosition(rect.getPosition());
}

void player::displayHP() {

}

void player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rect.move(-movementSpeed, 0);

		if (counterWalking == 0)
			sprite.setTextureRect(sf::IntRect(660, 150, 63, 90));

		if (counterWalking == 1)
			sprite.setTextureRect(sf::IntRect(731, 146, 61, 93));

		if (counterWalking == 2)
			sprite.setTextureRect(sf::IntRect(800, 145, 54, 94));

		if (counterWalking == 3)
			sprite.setTextureRect(sf::IntRect(862, 144, 54, 95));

		if (counterWalking == 4)
			sprite.setTextureRect(sf::IntRect(924, 145, 61, 94));

		if (counterWalking == 5)
			sprite.setTextureRect(sf::IntRect(993, 146, 63, 93));

		direction = 3;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rect.move(movementSpeed, 0);

		if (counterWalking == 0)
		sprite.setTextureRect(sf::IntRect(22, 149, 65, 90));

		if (counterWalking == 1)
			sprite.setTextureRect(sf::IntRect(94, 144, 71, 94));

		if (counterWalking == 2)
			sprite.setTextureRect(sf::IntRect(172, 143, 68, 96));

		if (counterWalking == 3)
			sprite.setTextureRect(sf::IntRect(248, 142, 60, 96));

		if (counterWalking == 4)
			sprite.setTextureRect(sf::IntRect(315, 142, 55, 95));

		if (counterWalking == 5)
			sprite.setTextureRect(sf::IntRect(376, 142, 58, 95));

		direction = 4;
	}

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 0, 64, 64));
		direction = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 0, 64, 64));
		direction = 2;
	}
	*/


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		
		zegar.restart();
		counterAttack = 0;

		sprite.setTextureRect(sf::IntRect(115, 263, 107, 95));

		

			if (zegar.getElapsedTime().asMilliseconds() == 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(29, 264, 79, 94));
					cout << "Dziala1" << endl;
					cout << counterAttack << endl;
					counterAttack++;
					zegar.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(115, 263, 107, 95));
					cout << "Dziala2" << endl;
					cout << counterAttack << endl;
					counterAttack++;
					zegar.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(230, 264, 77, 94));
					cout << "Dziala3" << endl;
					cout << counterAttack << endl;
					counterAttack++;
					zegar.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(315, 264, 66, 94));
					cout << "Dziala4" << endl;
					cout << counterAttack << endl;
					counterAttack++;
					zegar.restart();
				}
			
			

			}			
		direction = 3;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		rect.move(0, movementSpeed);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 128, 64, 64));
		direction = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 0, 64, 64));
		direction = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		rect.move(0, movementSpeed);
		sprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking), 128, 64, 64));
		direction = 1;
	}

	counterWalking++;
	if (counterWalking == 5)counterWalking = 0;
	//if (counterAttack == 4)counterAttack = 0;

}
