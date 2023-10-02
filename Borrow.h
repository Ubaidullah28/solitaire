#pragma once
//#include<sfml/graphics.hpp>
#include "StackP.h"
#include "Fanned.h"
#include "stock.h"


class borrowPile : public stackPile, public fannedPile
{
public:
	borrowPile(sf::Vector2i = sf::Vector2i(0, 0), sf::Vector2f = sf::Vector2f(30.0, 15.0));
	borrowPile(sf::Vector2i offset, sf::Vector2f visibility)
		: waste(nullptr), pile(offset), fannedPile(offset, fannedPile::RIGHT, visibility), stackPile(offset) {
	}

	void addToStock(stockPile& p) {
		while (waste.getSize() > 0) {
			p.appendCard(waste.cards.back());
			waste.cards.pop_back();
		}
	}

	void sendAllToWaste() {
		for (unsigned int i = 0; i < getSize(); i++) {
			cards[i].flip();
			waste.appendCard(cards[i]);
		}
		cards.clear();
	}

	bool canSplit(unsigned int cardIndex) {
		return stackPile::canSplit(cardIndex);
	}


	bool canAppend(const pile& p) {
		return false;
	}


	~borrowPile(void) {
	}

private:
	stockPile waste;
};

