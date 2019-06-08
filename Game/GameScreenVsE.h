#pragma once
#include <memory>
#include "Game.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Music.hpp>
#include "projectile.h"
#include "enemy.h"
#include "player.h"
#include "playerb.h"

class GameScreenVsE : public State
{
public:
	GameScreenVsE(std::shared_ptr<GameBase> data);

	void handleInput() override;
	void update() override;
	void draw() override;

private:
	std::shared_ptr<GameBase> data_;

	sf::Clock clock1;
	sf::Clock clock2;
	sf::Clock clock3;
	sf::Clock clock4;

	sf::Clock clock1b;
	sf::Clock clock2b;
	sf::Clock clock3b;
	sf::Clock clock4b;

	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;

	sf::Sprite sbackground;
	sf::Sprite characterSprite;
	sf::Music music;

	// Klasa postaci
	player Player;

	// Wektor pociskow
	std::vector<projectile>::const_iterator iter;
	std::vector<projectile> projectileArray;

	// Klasa pocisku
	projectile projectile1;

	// Wektor przeciwnikow
	std::vector<enemy>::const_iterator iter2;
	std::vector<enemy> enemyArray;

	// Klasa przeciwinka
	enemy Enemy;

};

