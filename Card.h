#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include"Deck.h"
#include"Game.h"
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;


enum class Suit { Hearts, Diamonds, Clubs, Spades };
enum class Rank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

class Card
{

private:
    Suit suit;
    Rank rank;
    bool FaceUp;

public:
    Card(Suit s, Rank r, bool faceUp = false) : suit(s), rank(r), FaceUp(faceUp) {}
    void Flip() { FaceUp = !FaceUp; }
    void Display() const {
        if (FaceUp) {
            cout << rankToString() << " of " << suitToString();
        }
        else {
            cout << "Card is face down";
        }
    }
    string suitToString() const
    {
        switch (suit)
        {
        case Suit::Hearts:
            return "Hearts";
        case Suit::Diamonds:
            return "Diamonds";
        case Suit::Clubs:
            return "Clubs";
        case Suit::Spades:
            return "Spades";
        default:
            return "Invalid Suit";
        }
    }
    string rankToString() const
    {
        switch (rank)
        {
        case Rank::Ace:
            return "Ace";
        case Rank::Two:
            return "Two";
        case Rank::Three:
            return "Three";
        case Rank::Four:
            return "Four";
        case Rank::Five:
            return "Five";
        case Rank::Six:
            return "Six";
        case Rank::Seven:
            return "Seven";
        case Rank::Eight:
            return "Eight";
        case Rank::Nine:
            return "Nine";
        case Rank::Ten:
            return "Ten";
        case Rank::Jack:
            return "Jack";
        case Rank::Queen:
            return "Queen";
        case Rank::King:
            return "King";
        default:
            return "Invalid Rank";
        }
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
