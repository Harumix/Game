#include "playerb.h"

playerb::playerb()
{
	rect.setSize(sf::Vector2f(50, 100));
	rect.setPosition(500, 125);
	rect.setFillColor(sf::Color::Cyan);
	sprite.setTextureRect(sf::IntRect(22, 149, 65, 90));
	sprite.setScale(sf::Vector2f(1, 1));
}

void playerb::update()
{
	sprite.setPosition(rect.getPosition());
}

void playerb::displayHP() {

}

void playerb::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !animating && !animating2 && !animating3 && !animating4)
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !animating && !animating2 && !animating3 && !animating4)
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


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8) && !animating && !animating2 && !animating3 && !animating4)
	{
		animating = true;
		animacja.restart();
		counterAttack = 0;
		sprite.setTextureRect(sf::IntRect(115, 263, 107, 95));
		rect.setSize(sf::Vector2f(107, 95));
	}

	if (animating) {
		if (animacja.getElapsedTime().asMilliseconds() >= 400) {

			if (counterAttack == 0) {
				sprite.setTextureRect(sf::IntRect(29, 264, 79, 94));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 1) {
				sprite.setTextureRect(sf::IntRect(115, 263, 107, 95));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 2) {
				sprite.setTextureRect(sf::IntRect(230, 264, 77, 94));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 3) {
				sprite.setTextureRect(sf::IntRect(315, 264, 66, 94));
				animating = false;
			}
		}
		direction = 3;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9) && !animating && !animating2 && !animating3 && !animating4)
	{
		animating2 = true;
		animacja.restart();
		counterAttack = 0;
		sprite.setTextureRect(sf::IntRect(642, 265, 109, 93));
	}

	if (animating2) {
		if (animacja.getElapsedTime().asMilliseconds() >= 400) {

			if (counterAttack == 0) {
				sprite.setTextureRect(sf::IntRect(563, 264, 71, 93));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 1) {
				sprite.setTextureRect(sf::IntRect(642, 265, 109, 93));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 2) {
				sprite.setTextureRect(sf::IntRect(759, 264, 71, 94));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 3) {
				sprite.setTextureRect(sf::IntRect(838, 264, 65, 94));
				animating2 = false;
			}
		}
		direction = 3;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5) && !animating && !animating2 && !animating3 && !animating4)
	{
		animating3 = true;
		animacja.restart();
		counterAttack = 0;
		sprite.setTextureRect(sf::IntRect(162, 23, 101, 86));
	}

	if (animating3) {
		if (animacja.getElapsedTime().asMilliseconds() >= 400) {

			if (counterAttack == 0) {
				sprite.setTextureRect(sf::IntRect(4, 10, 83, 99));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 1) {
				sprite.setTextureRect(sf::IntRect(95, 17, 59, 92));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 2) {
				sprite.setTextureRect(sf::IntRect(162, 23, 101, 86));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 3) {
				sprite.setTextureRect(sf::IntRect(271, 23, 55, 86));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 4) {
				sprite.setTextureRect(sf::IntRect(334, 10, 82, 101));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 5) {
				sprite.setTextureRect(sf::IntRect(425, 17, 66, 94));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 6) {
				sprite.setTextureRect(sf::IntRect(425, 17, 66, 94));
				animating3 = false;
			}
		}
		direction = 3;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6) && !animating && !animating2 && !animating3 && !animating4)
	{
		animating4 = true;
		animacja.restart();
		counterAttack = 0;
		sprite.setTextureRect(sf::IntRect(761, 28, 113, 99));
	}

	if (animating4) {
		if (animacja.getElapsedTime().asMilliseconds() >= 400) {

			if (counterAttack == 0) {
				sprite.setTextureRect(sf::IntRect(511, 36, 67, 91));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 1) {
				sprite.setTextureRect(sf::IntRect(586, 21, 73, 106));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 2) {
				sprite.setTextureRect(sf::IntRect(667, 6, 86, 121));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 3) {
				sprite.setTextureRect(sf::IntRect(761, 28, 113, 99));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 4) {
				sprite.setTextureRect(sf::IntRect(882, 39, 114, 88));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 5) {
				sprite.setTextureRect(sf::IntRect(1004, 35, 94, 92));
				counterAttack++;
				animacja.restart();
			}

			if (counterAttack == 6) {
				sprite.setTextureRect(sf::IntRect(425, 17, 66, 94));
				animating4 = false;
			}
		}
		direction = 3;
	}

	counterWalking++;
	if (counterWalking == 5)counterWalking = 0;
	//if (counterAttack == 4)counterAttack = 0;

}
