#pragma once
#include "State.hpp"
#include <memory>
#include "Game.hpp"

class ChoiceScreen : public State
{
public:
	ChoiceScreen(std::shared_ptr<GameBase> data);

	void handleInput() override;
	void update() override;
	void draw() override;

private:
	std::shared_ptr<GameBase> data_;
	sf::Sprite sbackground_;
	sf::Texture tbackground_;
};

