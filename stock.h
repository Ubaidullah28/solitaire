#pragma once
#include"sqPiles.h"
#include"pile.h"
class borrowPile;

class stockPile : public sqPile
{
	borrowPile* bPile;
public:
	stockPile(borrowPile* _bPile, sf::Vector2i _offset = sf::Vector2i(0, 0))
		: pile(_offset), sqPile(_offset), bPile(_bPile)
	{
	}
	bool isSplit(size_t s)
	{
		return false;
	}

	bool isAppend(const pile&p)
	{
		return false;
	}
	
};
