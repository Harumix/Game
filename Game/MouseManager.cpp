#include "MouseManager.h"
#include <random>


	bool MouseManager::isSpriteClicked(sf::Sprite const &object, sf::Mouse::Button const &button, sf::RenderWindow const &window) const
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect tempRect{ static_cast<sf::IntRect>(object.getGlobalBounds()) };

			return tempRect.contains(getMousePosition(window));
		}

		return false;
	}

	bool MouseManager::isMouseOverSprite(sf::Sprite const& object, sf::RenderWindow const& window) const
	{
		sf::IntRect tempRect{ static_cast<sf::IntRect>(object.getGlobalBounds()) };

		return tempRect.contains(getMousePosition(window));
	}

	sf::Vector2i MouseManager::getMousePosition(sf::RenderWindow const &window) const
	{
		return sf::Mouse::getPosition(window);
	}
