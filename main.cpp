#include"Card.h"
#include"Deck.h"
#include"Game.h"
#include<iostream>
using namespace std;



int main() 
{
    srand(static_cast<unsigned>(time(nullptr)));
    Game solitaire;
    solitaire.Start();
    return 0;
}