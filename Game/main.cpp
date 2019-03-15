#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "ResourcePath.hpp""

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// Tworzenie okna 
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
	// Pozycja startowa okna
	window.setPosition(sf::Vector2i(100, 50));
	// Rozmiar okna
	window.setSize(sf::Vector2u(800, 600));
	// Nazwa okna
	window.setTitle("Game");

	// Set the Icon
	sf::Image icon;
	if (!icon.loadFromFile("../External/Graphics/Lion.jpg")) {
		return EXIT_FAILURE;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Load a sprite to display
	sf::Texture lionTexture;
	if (!lionTexture.loadFromFile("../External/Graphics/Lion.jpg")) {
		return EXIT_FAILURE;
	}
	sf::Sprite lionSprite(lionTexture);

	/*

	// Create a graphical text to display
	sf::Font font;
	if (!font.loadFromFile("font.ttf")) {
		//return EXIT_FAILURE;
	}
	sf::Text text("Hello World", font, 50);

	// Load a music to play
	sf::Music music;
	if (!music.openFromFile("music.mp3")) {
		//return EXIT_FAILURE;
	}

	// Play music
	music.play();

	*/

	// Start the game loop
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
		window.draw(lionSprite);

		// Draw the string
		//window.draw(text);

		// Update the window
		window.display();

	}

	return 0;
}