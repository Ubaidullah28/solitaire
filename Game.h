#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include"Card.h"
#include"Deck.h"
#include"Game.h"
#include <queue>
#include <cstdlib>
#include"Card.h"
#include"Deck.h"
#include"Game.h"
#include <ctime>
#include<iostream>
using namespace std;


class Game 
{
public:
    Game()
    {
        // Initialize the game, including main deck, sub-decks, and score


    }

    void Start()
    {
        // Implement the game loop
    }

    void DisplayGameState()
    {
        // Implement function to display the current game state
    }

    bool IsGameOver()
    {
        // Implement win/lose conditions
    }

private:
    stack<Card> mainDeck;
    vector<std::queue<Card>> subDecks;
    vector<Card> foundationDecks;
    Deck* d;
    int score;
   
  
};

