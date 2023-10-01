#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "card.h"



class pileofCard : public Card
{
	sf::Sprite sprite;
	sf::Texture const* texture;

public:
	static const  size_t width = 100;
	static const  size_t height = 140;
	enum cardSides { face_front, face_back };
	 cardSides sides;


	pileofCard(Rank _rank,Suit _suit, cardSides _or , sf::Sprite _sprite) : Card(_suit, _rank), sides(_or)
	{
		texture = Game::getTexture(*this);
		sprite.setTexture(*texture);
		sf::Vector2u size = texture->getSize();
		sprite.setScale(float(width) / size.x, float(height) / size.y);
	}

	pileofCard(const pileofCard& s) :Card(s) 
	{

		sides = s.sides;
		texture = s.texture;
		sprite.setTexture(*texture);
		sf::Vector2u size = texture->getSize();
		sprite.setScale(float(width) / size.x, float(height) / size.y);
	
	}

	void draw(sf::RenderWindow& win) 
	{
		win.draw(sprite);
	}


	Card getCard() const 
	{
		return Card(getSuit(), getRank());
	}

	cardSides getSide() const 
	{
		return sides;
	}


	void drawPileofCard(sf::RenderWindow& win) 
	{
		win.draw(sprite);
	}


	Suit getSuit() const
	{
		return suit;
	}
	Rank getRank() const
	{
		return rank;
	}
};
