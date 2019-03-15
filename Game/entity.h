#pragma once
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include "ResourcePath.hpp"
#include <cstdlib>
#include <functional>
#include <deque>
#include <list>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

class entity
{
public:
	// Obiekty fizyczne
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
};


