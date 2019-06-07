#include "PvPScreen.h"
#include <SFML/Window/Event.hpp>
#include "GameScreenVsP.h"

PvPScreen::PvPScreen(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void PvPScreen::handleInput()
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
			data_->maschine.addState(std::make_unique<GameScreenVsP>(data_), true);
		}
	}
}

void PvPScreen::update() {}

void PvPScreen::draw()
{
	data_->window.clear(sf::Color::Red);
	data_->window.display();
}