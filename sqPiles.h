#pragma once
#include"utility.h"
#include"pile.h"


class sqPile : virtual public pile
{
public:
	sqPile(sf::Vector2i = sf::Vector2i(0, 0))
	{

	}

	void draw(sf::RenderWindow & win) 
	{
		if (getSize() == 0)
		{
				drawEmpty(win);
		}
		else
		{
				cards.back().draw(win);
		}
	}


	size_t getWidth() const 
	{
		return pileofCard::width;
	}

	size_t getHeight() const 
	{
		return pileofCard::height;
	}
	void resetPos();
	int getCardAt(sf::Vector2i point);

	sf::Vector2i getCardPosition(size_t)
	{
		return offset;
	}

};

