#pragma once
#include <SFML/Graphics.hpp>
#include <random>

class MouseManager
{
public:
	bool isSpriteClicked(sf::Sprite const& object, sf::Mouse::Button const& button, sf::RenderWindow const& window) const;
	bool isMouseOverSprite(sf::Sprite const& object, sf::RenderWindow const& window) const;
	sf::Vector2i getMousePosition(sf::RenderWindow const& window) const;
};

template<typename T>
T Random(T leftRange, T rightRange)
{
	std::default_random_engine engine{ std::random_device{}() };

	using dist = std::conditional_t<
		std::is_integral<T>::value,
		std::uniform_int_distribution<T>,
		std::uniform_real_distribution<T>
	>;

	return dist{ leftRange, rightRange }(engine);
}
