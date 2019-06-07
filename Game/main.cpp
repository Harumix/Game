#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "ResourcePath.hpp"
#include "player.h"
#include "projectile.h"
#include "enemy.h"
#include "random.h"
#include "Game.hpp"

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int main()
{
	Game Tussle(600, 222, "The Tussle");
	//Game Tussle(1270, 720, "The Tussle");
	/*
	sf::Clock clock1;
	sf::Clock clock2;
	sf::Clock clock3;
	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;

	// Tworzenie okna 
	sf::RenderWindow window(sf::VideoMode(660, 222), "Game");
	// Pozycja startowa okna
	window.setPosition(sf::Vector2i(20, sf::VideoMode::getDesktopMode().height / 5));
	// Rozmiar okna
	window.setSize(sf::Vector2u(1320, 440));
	// Nazwa okna
	window.setTitle("Game");
	window.setFramerateLimit(60);
	// Ikona okna
	sf::Image icon;
	if (!icon.loadFromFile("../External/Graphics/Lion.jpg")) {
		return EXIT_FAILURE;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	//Tlo gry
	sf::Sprite sbackground;
	sf::Texture tbackground;
	tbackground.loadFromFile("../External/Graphics/street.png");
	sbackground.setTexture(tbackground);
	sf::Vector2u size = tbackground.getSize();
	//sbackground.setScale(sf::Vector2f(2,2));
	//sbackground.setOrigin(size.x/4, size.y/4);

	// Sprite Postaci
	sf::Texture characterTexture;
	if (!characterTexture.loadFromFile("../External/Graphics/Character.png")) {
		return EXIT_FAILURE;
	}
	sf::Sprite characterSprite(characterTexture);
	characterTexture.setSmooth(true);

	// Tekst Naglowkowy
//sf::Font Odelette;
//if (!Odelette.loadFromFile("../External/Fonts/Odelette.ttf")) {
//	return EXIT_FAILURE;
//}
//sf::Text text("Game", Odelette, 50);
//text.setFillColor(sf::Color::Red);
//text.setPosition(400,0);

// Tworzenie muzyki
	sf::Music music;
	if (!music.openFromFile("../External/Music/PumpedUpKicks.ogg"))
		return -1;
	music.setVolume(1);
	music.play();

	// Klasa postaci
	class player Player1;
	Player1.sprite.setTexture(characterTexture);


	// Wektor pociskow
	vector<projectile>::const_iterator iter;
	vector<projectile> projectileArray;

	// Klasa pocisku
	class projectile projectile1;

	// Wektor przeciwnikow
	vector<enemy>::const_iterator iter2;
	vector<enemy> enemyArray;

	// Klasa przeciwinka
	class enemy enemy1;
	enemy1.sprite.setTexture(characterTexture);
	//enemy1.rect.setPosition(200, 200);
	enemyArray.push_back(enemy1);


	// Petla gry
	while (window.isOpen())
	{
		//Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// Escape pressed: exit
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}

		// Clear screen
		window.clear();

		window.draw(sbackground);

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

			if :(sf:Keyboard::isKeyPressed(sf::Keyboard::Space))
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
			window.draw(projectileArray[counter].rect);
			counter++;
		}

		// Draw Enemies
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) {
			enemyArray.push_back(enemy1);
		}

		counter2 = 0;
		for (iter2 = enemyArray.begin(); iter2 != enemyArray.end(); iter2++)
		{
			window.draw(enemyArray[counter2].rect);
			enemyArray[counter2].update();
			enemyArray[counter2].updateMovement();
			window.draw(enemyArray[counter2].sprite);
			counter2++;
		}

		// Draw Player
		window.draw(Player1.sprite);

		// Update Player
		Player1.update();
		Player1.updateMovement();

		// Draw the string
		//window.draw(text);

		// Update the window
		window.display();

	}
	*/
	return 0;
}