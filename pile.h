#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include<stack>
#include"utility.h"
#include"pileOfCards.h"
using namespace std;

class stickyPile;

class pile
{
	sf::Sprite emptyCard;
	sf::Texture emptyCardTex;

public:

	vector<pileofCard> cards;
	sf::Vector2i offset;


	static sf::Texture loadTexture(const string& filename) 
	{
		sf::Texture texture;

		if (!texture.loadFromFile(filename)) 
		{
		
			cout << "image not found!! " << filename << endl;
		}

		return texture;
	}

	pile(sf::Vector2i _offset) : offset(_offset) 
	{
		emptyCardTex = loadTexture("textures//empty.png");
		emptyCard.setTexture(emptyCardTex);
		sf::Vector2u size = emptyCardTex.getSize();
		emptyCard.setScale(float(pileofCard::width) / size.x, float(pileofCard::height) / size.y);
		emptyCard.setPosition(float(offset.x), float(offset.y));
	}

	size_t getSize() const 
	{
		return cards.size();
	}

	sf::Vector2i getOffset() const 
	{
		return offset;
	}

	int getWidth()
	{
		return Width;
	}
	int getHeight()
	{
		return Height;
	}
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void resetCardPositions() = 0;

	bool isOverlapping(const pile& p) 
	{
		int thisWidth = getWidth();
		int thisHeight = getHeight();
		bool overlappingOnX = offset.x < p.offset.x + Width && offset.x + thisWidth > p.offset.x;
		bool overlappingOnY = offset.y < p.offset.y + Height && offset.y + thisHeight > p.offset.y;
		return (overlappingOnX && overlappingOnY);
	}

	void drawEmpty(sf::RenderWindow& win)
	{
		emptyCard.setPosition(float(offset.x), float(offset.y));
		win.draw(emptyCard);
	}

	void setPosition(sf::Vector2i _offset) 
	{
		offset = _offset;
		resetCardPositions();
	}







};
