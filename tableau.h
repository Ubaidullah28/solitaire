#pragma once
#include <SFML/Graphics.hpp>
#include"pile.h"

class tableau 
{
public:
	tableau(sf::Vector2i offset = sf::Vector2i(0, 0), sf::Vector2f visibility = sf::Vector2f(28.0, 14.0))
		
	{

	}

	bool canSplit(unsigned int);
	bool canAppend(const pile&);
};
