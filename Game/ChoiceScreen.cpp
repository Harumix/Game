#include "ChoiceScreen.h"
#include <SFML/Window/Event.hpp>
#include "PvEScreen.h"
#include "PvPScreen.h"
#include "StartScreen.h"

ChoiceScreen::ChoiceScreen(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void ChoiceScreen::handleInput()
{
	sf::Event event{};
	while (data_->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			data_->window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<StartScreen>(data_), true);
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<PvEScreen>(data_), true);
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<PvPScreen>(data_), true);
		}
	}
}

void ChoiceScreen::update() {}

void ChoiceScreen::draw()
{
	tbackground_.loadFromFile("../External/Graphics/ChoiceScreen.jpg");
	sbackground_.setTexture(tbackground_);
	tbackground_.setSmooth(true);

	data_->window.clear(sf::Color::White);
	data_->window.draw(sbackground_);
	data_->window.display();
}