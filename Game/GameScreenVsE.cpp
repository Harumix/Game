#include <SFML/Window/Event.hpp>
#include "GameScreenVsE.h"
#include "StartScreen.h"

GameScreenVsE::GameScreenVsE(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void GameScreenVsE::handleInput()
{
	sf::Event event{};
	while (data_->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			data_->window.close();
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<StartScreen>(data_), true);
		}
	}
}

void GameScreenVsE::update() {

	sf::Time elapsed1 = clock1.getElapsedTime();

	sf::Time elapsed1b = clock1b.getElapsedTime();

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::U) || sf::Keyboard::isKeyPressed(sf::Keyboard::I) || sf::Keyboard::isKeyPressed(sf::Keyboard::J) || sf::Keyboard::isKeyPressed(sf::Keyboard::K)) && Player.rect.getGlobalBounds().intersects(Enemy.rect.getGlobalBounds()) && elapsed1.asMilliseconds() >= 400) {
		Enemy.hp -= 10;
		if (Enemy.hp <= 0) Enemy.alive = false;
		std::cout << Enemy.hp << endl;
		clock1.restart();
	}

	if (Enemy.attack && Enemy.rect.getGlobalBounds().intersects(Player.rect.getGlobalBounds()) && elapsed1b.asMilliseconds() >= 400) {
		Player.hp -= 10;
		if (Player.hp <= 0) Player.alive = false;
		std::cout << Player.hp << endl;
		clock1b.restart();
	}

	Player.update();
	Player.updateMovement();
	Enemy.updateMovement();
	Enemy.update();

}

void GameScreenVsE::draw()
{

	sf::Texture tbackground;
	tbackground.loadFromFile("../External/Graphics/street.png");
	sbackground.setTexture(tbackground);

	sf::Texture characterTexture;
	characterTexture.loadFromFile("../External/Graphics/Character3.png");
	characterSprite.setTexture(characterTexture);

	Player.sprite.setTexture(characterTexture);
	Enemy.sprite.setTexture(characterTexture);

	data_->window.clear(sf::Color::Cyan);
	data_->window.draw(sbackground);
	data_->window.draw(Player.sprite);
	data_->window.draw(Enemy.sprite);
	data_->window.display();
}