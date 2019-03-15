#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "ResourcePath.hpp""
#include "player.h"
#include "projectile.h"
#include "enemy.h"
#include "random.h"

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int main()
{
	int counter = 0;
	int counter2 = 0;

	// Tworzenie okna 
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
	// Pozycja startowa okna
	window.setPosition(sf::Vector2i(100, 50));
	// Rozmiar okna
	window.setSize(sf::Vector2u(800, 600));
	// Nazwa okna
	window.setTitle("Game");

	// Ikona okna
	sf::Image icon;
	if (!icon.loadFromFile("../External/Graphics/Lion.jpg")) {
		return EXIT_FAILURE;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Sprite Postaci
	sf::Texture characterTexture;
	if (!characterTexture.loadFromFile("../External/Graphics/character.png")) {
		return EXIT_FAILURE;
	}
	sf::Sprite characterSprite(characterTexture);

	// Tekst Naglowkowy
	sf::Font Odelette;
	if (!Odelette.loadFromFile("../External/Fonts/Odelette.ttf")) {
		return EXIT_FAILURE;
	}
	sf::Text text("Game", Odelette, 50);
	text.setFillColor(sf::Color::Red);
	text.setPosition(400,0);

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
	enemy1.rect.setPosition(200, 200);
	enemyArray.push_back(enemy1);
	enemyArray.push_back(enemy1);
	enemyArray.push_back(enemy1);
	enemyArray.push_back(enemy1);
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

		// Create projectiles
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2, Player1.rect.getPosition().y + Player1.rect.getSize().y/2);
			projectile1.direction = Player1.direction;
			projectileArray.push_back(projectile1);
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
		counter2 = 0;
		for (iter2 = enemyArray.begin(); iter2 != enemyArray.end(); iter2++)
		{
			//window.draw(enemyArray[counter2].rect);
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
		window.draw(text);

		// Update the window
		window.display();

	}

	return 0;
}