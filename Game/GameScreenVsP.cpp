#include <SFML/Window/Event.hpp>
#include "GameScreenVsP.h"
#include "StartScreen.h"

GameScreenVsP::GameScreenVsP(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void GameScreenVsP::handleInput()
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

void GameScreenVsP::update()
{
	sf::Time elapsed1 = clock1.getElapsedTime();
	sf::Time elapsed2 = clock2.getElapsedTime();

	//DMG
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::U) || sf::Keyboard::isKeyPressed(sf::Keyboard::I) || sf::Keyboard::isKeyPressed(sf::Keyboard::J) || sf::Keyboard::isKeyPressed(sf::Keyboard::K)) && Player1.rect.getGlobalBounds().intersects(Player2.rect.getGlobalBounds()) && elapsed1.asMilliseconds() >= 400) {
		Player2.hp -= 10;
		if (Player2.hp <= 0) Player2.alive = false;
		std::cout << Player2.hp << endl;
		clock1.restart();
	}
	
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) && Player2.rect.getGlobalBounds().intersects(Player1.rect.getGlobalBounds()) && elapsed2.asMilliseconds() >= 400) {
		Player1.hp -= 10;
		if (Player1.hp <= 0) Player1.alive = false;
		std::cout << Player1.hp << endl;
		clock2.restart();
	}

	Player1.update();
	Player1.updateMovement();
	Player2.update();
	Player2.updateMovement();
}

void GameScreenVsP::draw()
{
	sf::Texture tbackground;
	tbackground.loadFromFile("../External/Graphics/street.png");
	sbackground.setTexture(tbackground);

	sf::Texture characterTexture;
	characterTexture.loadFromFile("../External/Graphics/Character3.png");
	characterSprite.setTexture(characterTexture);

	Player1.sprite.setTexture(characterTexture);
	Player2.sprite.setTexture(characterTexture);

	data_->window.clear();
	data_->window.draw(sbackground);
	data_->window.draw(Player1.sprite);
	data_->window.draw(Player2.sprite);

	for (auto& i : projectileArray)
	{
		data_->window.draw(i.rect);
	}
	
	data_->window.display();
}