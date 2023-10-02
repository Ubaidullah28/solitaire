#pragma once
#include "PileofCards.h"
#include "pile.h"


class stackPile : virtual public pile
{
public:
	stackPile(sf::Vector2i = sf::Vector2i(0, 0));
	stackPile(sf::Vector2i offset) :pile(offset) {
	}

	bool canSplit(unsigned int cardIndex) {
		return commonSplitTest(cardIndex) && cardIndex == getSize() - 1;
	}

	~stackPile(void) {
	}
};

