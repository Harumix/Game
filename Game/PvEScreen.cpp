#include "PvEScreen.h"
#include <SFML/Window/Event.hpp>
#include "GameScreenVsE.h"

PvEScreen::PvEScreen(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void PvEScreen::handleInput()
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
			data_->maschine.addState(std::make_unique<GameScreenVsE>(data_), true);
		}
	}
}

void PvEScreen::update() {}

void PvEScreen::draw()
{
	data_->window.clear(sf::Color::Green);
	data_->window.display();
}