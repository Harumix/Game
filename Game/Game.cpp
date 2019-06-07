#include "Game.hpp"
#include "StartScreen.h"


Game::Game(const unsigned width, const unsigned height, const std::string& title)
{
	data_->window.create(sf::VideoMode(width, height), title);
	data_->window.setFramerateLimit(60);
	data_->window.setPosition(sf::Vector2i(20, sf::VideoMode::getDesktopMode().height / 5));
	data_->maschine.addState(std::unique_ptr<State>(std::make_unique<StartScreen>(data_)), false);
	data_->window.setSize(sf::Vector2u(1320, 440));

	run();
}

void Game::run() const
{
	while (data_->window.isOpen())
	{
		data_->maschine.processStateChanges();
		data_->maschine.getActiveState()->handleInput();
		data_->maschine.getActiveState()->update();
		data_->maschine.getActiveState()->draw();
	}
}
