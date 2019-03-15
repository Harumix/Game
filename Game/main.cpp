#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "ResourcePath.hpp""

using std::cout;
using std::cin;
using std::endl;

int main()
{
	//Zmienne
	float movementSpeed = 0.025;
	int counterWalking = 0;

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
		//return EXIT_FAILURE;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Tworzenie Sprite
	sf::Texture characterTexture;
	if (!characterTexture.loadFromFile("../External/Graphics/character.png")) {
		return EXIT_FAILURE;
	}
	sf::Sprite characterSprite(characterTexture);
	characterSprite.setPosition(150, 150);
	characterSprite.setTextureRect(sf::IntRect(128, 128, 64, 64));

	// Tworzenie tekstu
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
	music.setVolume(10);
	music.play();


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

		// Draw the sprite
		window.draw(characterSprite);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			characterSprite.move(-movementSpeed, 0);
			characterSprite.setTextureRect(sf::IntRect(0+(64*counterWalking),64, 64, 64));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			characterSprite.move(movementSpeed, 0);
			characterSprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking),192, 64, 64));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			characterSprite.move(0, -movementSpeed);
			characterSprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking),0, 64, 64));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			characterSprite.move(0, movementSpeed);
			characterSprite.setTextureRect(sf::IntRect(0 + (64 * counterWalking),128, 64, 64));
		}

		counterWalking++;

		if (counterWalking == 9) {
			counterWalking = 0;
		}

		// Draw the string
		window.draw(text);

		// Update the window
		window.display();

	}

	return 0;
}