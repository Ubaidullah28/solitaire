#include"Card.h"
#include"Deck.h"
#include"Game.h"
#include <SFML/Graphics.hpp>
#include "utility.h"
#include"pile.h"
#include<iostream>
using namespace std;





void main() 
{
	srand(time(0));
	string filename;
	sf::RenderWindow window;
	window.create(sf::VideoMode(Width,Height), "Ubaidullah & Abdullah Solitaire", sf::Style::Close);
	window.setPosition(sf::Vector2i(50, 0));
	pile::loadTexture(filename);
	Game g;
	bool win = g.checkWin(), lost = g.checkLose();
	int score = 0;
	while (window.isOpen() && !win && !lost) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				/*g.onMouseDown(sf::Mouse::getPosition(window));*/
			 if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) 
			{
				/*g.onMouseUp();*/
				win = g.checkWin();
				score++;
				lost = g.checkLose();
			}
			/*else if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			*/	/*g.onMouseMove(sf::Mouse::getPosition(window));*/
		}

		window.clear(sf::Color::White);
		g.draw(window);
		window.display();
	}
}



