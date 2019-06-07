#include <SFML/Window/Event.hpp>
#include "GameScreenVsP.h"
#include "StartScreen.h"

GameScreenVsP::GameScreenVsP(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void GameScreenVsP::handleInput()
{
	sf::Event event{};
	while (data_->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			data_->window.close();
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<StartScreen>(data_), true);
		}
	}
}

void GameScreenVsP::update()
{
	sf::Time elapsed1 = clock1.getElapsedTime();
	sf::Time elapsed2 = clock2.getElapsedTime();
	sf::Time elapsed3 = clock3.getElapsedTime();

	//Colission
	counter = 0;
	for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
	{
		counter2 = 0;
		for (iter2 = enemyArray.begin(); iter2 != enemyArray.end(); iter2++)
		{
			if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds())) {
				projectileArray[counter].destroy = true;
				enemyArray[counter2].hp -= projectile1.attackDamage;
				if (enemyArray[counter2].hp <= 0) enemyArray[counter2].alive = false;
			}
			counter2++;
		}
		counter++;
	}

	//Delete Projectile
	counter = 0;
	for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
	{
		if (projectileArray[counter].destroy == true) {
			projectileArray.erase(iter);
			break;
		}

		counter++;
	}

	//Dead
	counter = 0;
	for (iter2 = enemyArray.begin(); iter2 != enemyArray.end(); iter2++)
	{
		if (enemyArray[counter].alive == false) {
			enemyArray.erase(iter2);
			break;
		}
		counter++;
	}
	// Create projectiles 
	if (elapsed1.asSeconds() >= 1) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2, Player1.rect.getPosition().y);
			projectile1.direction = Player1.direction;
			projectileArray.push_back(projectile1);
			clock1.restart();
		}
	}

	// Draw projectiles
	counter = 0;
	for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
	{
		projectileArray[counter].update();
		counter++;
	}

	// Draw Enemies
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) {
		enemyArray.push_back(enemy1);
	}

	counter2 = 0;
	for (iter2 = enemyArray.begin(); iter2 != enemyArray.end(); iter2++)
	{
		enemyArray[counter2].update();
		enemyArray[counter2].updateMovement();
		counter2++;
	}

	Player1.update();
	Player1.updateMovement();
}

void GameScreenVsP::draw()
{
	sf::Texture tbackground;
	tbackground.loadFromFile("../External/Graphics/street.png");
	sbackground.setTexture(tbackground);

	sf::Texture characterTexture;
	characterTexture.loadFromFile("../External/Graphics/Character3.png");
	characterSprite.setTexture(characterTexture);

	Player1.sprite.setTexture(characterTexture);
	enemy1.sprite.setTexture(characterTexture);
	enemyArray.push_back(enemy1);

	data_->window.clear();
	data_->window.draw(sbackground);
	data_->window.draw(Player1.sprite);
	//data_->window.draw(enemy1.rect);

	data_->window.draw(enemyArray[0].sprite);

	for (auto& i : projectileArray)
	{
		data_->window.draw(i.rect);
	}
	
	data_->window.display();
}