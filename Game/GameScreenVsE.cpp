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

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<StartScreen>(data_), true);
		}
	}
}

void GameScreenVsE::update() {}

void GameScreenVsE::draw()
{
	data_->window.clear(sf::Color::Cyan);
	data_->window.display();
}