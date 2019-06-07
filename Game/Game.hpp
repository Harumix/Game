#pragma once
#include "StateMaschine.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MouseManager.h"

struct GameBase
{
	sf::RenderWindow window;
	StateMaschine maschine;
	MouseManager mouse;
};

class Game
{
public:
	Game(unsigned width, unsigned height, const std::string& title);
	~Game() = default;

private:
	std::shared_ptr<GameBase> data_ = std::make_shared<GameBase>();

	void run() const;
};