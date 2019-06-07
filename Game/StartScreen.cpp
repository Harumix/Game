#include "StartScreen.h"
#include <SFML/Window/Event.hpp>
#include "ChoiceScreen.h"
#include <SFML/Audio.hpp>

StartScreen::StartScreen(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void StartScreen::handleInput()
{
	sf::Event event{};

	while (data_->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			data_->window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<ChoiceScreen>(data_), true);
		}
	}
}



void StartScreen::update() {}

void StartScreen::draw()
{
	tbackground_.loadFromFile("../External/Graphics/StartScreen.jpg");
	sbackground_.setTexture(tbackground_);
	tbackground_.setSmooth(true);

	data_->window.clear(sf::Color::White);
	data_->window.draw(sbackground_);
	data_->window.display();
	

}