#pragma once
#include "Fanned.h"

class stickyPile : public fannedPile
{
public:
	stickyPile(pile*, unsigned int, sf::Vector2i = sf::Vector2i(0, 0), sf::Vector2f = sf::Vector2f(30.0, 15.0));
	stickyPile(pile* p, unsigned int cardIndex, sf::Vector2i offset, sf::Vector2f visibility) :
		parentPile(p), pile(offset), fannedPile(offset, fannedPile::DOWN, visibility) {
		if (!p || cardIndex > p->getSize() - 1)
			throw string("Invalid pile...\n");

		for (unsigned int i = cardIndex; i < parentPile->getSize(); i++) {
			appendCard(parentPile->cards[i]);
		}

		for (unsigned int i = 0; i < getSize(); i++) {
			parentPile->cards.pop_back();
		}
	}

	void returnCards()
	{
		parentPile->appendPile(*this);
		cards.clear();
	}

	bool canSplit(unsigned int) {
		return false;
	}

	bool canAppend(const pile&) {
		return false;
	}

	void onMouseUp(const vector<pile*>& piles) {
		unsigned int i;
		for (i = 0; i < piles.size(); i++) {
			if (piles[i]->isOverlapping(*this) && piles[i] != parentPile)
				break;
		}

		if (i < piles.size() && piles[i]->canAppend(*this)) {
			if (parentPile->getSize() > 0 && parentPile->cards.back().getOrientation() == pileCard::FACE_DOWN)
				parentPile->cards[parentPile->getSize() - 1].flip();
			piles[i]->appendPile(*this);
		}
		else {
			returnCards();
		}
	}

	~stickyPile(void) {

	}

private:
	void returnCards();
	pile* parentPile;
};


