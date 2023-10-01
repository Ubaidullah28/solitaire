#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include"Card.h"
#include"Game.h"
#include <queue>
#include"Deck.h"
#include"Game.h">
#include"pileOfCards.h"
using namespace std;


class Game 
{
    Deck* d;
    int score;
public:
    static sf::Texture faceBack;
    static sf::Texture textures[Card::King + 1][Card::Clubs + 1];

   static sf::Texture* getTexture(const pileofCard& p) 
    {
        if (p.getSide() == pileofCard::face_back)
            return &faceBack;
        else
            return &textures[p.getRank()][p.getSuit()];
    }

   bool checkWin() 
   {
       /*for (unsigned int i = 0; i < 4; i++) {
           if (pile[i]->getSize() != 13)
               return false;
       }*/
       return true;
   }

   bool checkLose() 
   {
       return false;
   }



   void draw(sf::RenderWindow& win) 
   {
       ////win.draw(background);
       //for (unsigned int i = 0; i < win.getSize(); i++)
          
   }

};

