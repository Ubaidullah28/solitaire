#pragma once
#include "Pile.h"

class fannedPile : virtual public pile
{
private:
	fanDirection fanDir;
	sf::Vector2i getCardOffset() const;
	void resetCardPositions();
protected:
	sf::Vector2f percentageVisibility;
public:
	virtual bool canSplit(unsigned int) = 0;
	virtual bool canAppend(const pile&) = 0;
	enum fanDirection { RIGHT, DOWN };
	fannedPile(sf::Vector2i = sf::Vector2i(0, 0), fanDirection = RIGHT, sf::Vector2f = sf::Vector2f(30.0, 15.0));
	fannedPile(sf::Vector2i offset, fanDirection _fanDirection, sf::Vector2f visibility) : pile(offset) {
		fanDir = _fanDirection;
		percentageVisibility = visibility;
	}

	sf::Vector2i getCardOffset() const {
		int x = int(percentageVisibility.x / 100.0f * pileCard::WIDTH);
		int y = int(percentageVisibility.y / 100.0f * pileCard::HEIGHT);
		return sf::Vector2i(x, y);
	}

	int getCardAt(sf::Vector2i point) {
		if (!containsPoint(point))
			return -2;

		if (getSize() == 0)
			return -1;

		sf::Vector2i cardOffset = getCardOffset();
		unsigned int cardIndex;

		switch (fanDir) {
		case RIGHT:
			cardIndex = (point.x - offset.x) / cardOffset.x;
			break;
		case DOWN:
			cardIndex = (point.y - offset.y) / cardOffset.y;
			break;
		}

		if (cardIndex >= getSize())
			cardIndex = getSize() - 1;

		return cardIndex;
	}

	void draw(sf::RenderWindow& window) {
		if (getSize() == 0)
			drawEmpty(window);
		else
			for (unsigned int i = 0; i < getSize(); i++)
				cards[i].draw(window);
	}

	unsigned int getWidth() const {
		sf::Vector2i cardOffset = getCardOffset();
		return pileCard::WIDTH + ((fanDir == RIGHT && getSize() > 0) ? cardOffset.x * (getSize() - 1) : 0);
	}

	unsigned int getHeight() const {
		sf::Vector2i cardOffset = getCardOffset();
		return pileCard::HEIGHT + ((fanDir == DOWN && getSize() > 0) ? cardOffset.y * (getSize() - 1) : 0);
	}

	void resetCardPositions() {
		for (unsigned int i = 0; i < getSize(); i++) {
			sf::Vector2i offset = getCardPosition(i);
			cards[i].setOffset(offset);
		}
	}

	sf::Vector2i getCardPosition(unsigned int index) {
		sf::Vector2i cardOffset = getCardOffset();
		sf::Vector2i dirVec;
		switch (fanDir) {
		case RIGHT:
			dirVec = sf::Vector2i(1, 0);
			break;
		case DOWN:
			dirVec = sf::Vector2i(0, 1);
			break;
		}
		return sf::Vector2i(offset.x + index * dirVec.x * cardOffset.x, offset.y + dirVec.y * index * cardOffset.y);
	}


	~fannedPile(void) {
	}



	


};


