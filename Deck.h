#pragma once
#include <iostream>
#include<algorithm>
#include <vector>
#include <stack>
#include <queue>
#include"Card.h"
#include"Game.h"
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;
class Card;

class Deck
{
    vector<Card> cards;


public:

    Deck() 
    {
        for (int s = static_cast<int>(Suit::Hearts); s <= static_cast<int>(Suit::Spades); ++s) 
        {
            for (int r = static_cast<int>(Rank::Ace); r <= static_cast<int>(Rank::King); ++r) 
            {
                cards.push_back(Card(static_cast<Suit>(s), static_cast<Rank>(r), true));
            }
        }
        shuffleDeck();
    }


    void shuffleDeck() 
    {
        default_random_engine rng(static_cast<unsigned>(std::time(0)));

        shuffle(cards.begin(), cards.end(), rng);
    }

  

    bool isEmpty() const 
    {
        return cards.empty();
    }
 
    Card& Deal() 
    {
        if (!cards.empty()) 
        {
            Card& dealtCard = cards.back();
            cards.pop_back();

           
            cout << "Dealt: " << static_cast<int>(dealtCard.getRank()) << " of "
                << static_cast<int>(dealtCard.getSuit()) << endl;

            return dealtCard;
        }
        else 
        {
            cout << "Deck is empty!!" << endl;
            
            return cards.front();
        }
    }

    void AddCard(const Card& card) 
    {
        cards.push_back(card);
    }


    const Card& PeekTopCard() const 
    {
        if (!cards.empty()) 
        {
            return cards.back();
        }
        else {
            cout << "Deck is empty!!" << endl;
           
            return cards.front();
        }
    }

    void deleteDeck() 
    {
        cards.clear();
    }

};
