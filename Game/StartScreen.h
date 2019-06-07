#pragma once
#include "State.hpp"
#include "Game.hpp"

class StartScreen : public State
{
public:
	StartScreen(std::shared_ptr<GameBase> data);

	void handleInput() override;
	void update() override;
	void draw() override;

private:
	std::shared_ptr<GameBase> data_;
	sf::Sprite sbackground_;
	sf::Texture tbackground_;

};

