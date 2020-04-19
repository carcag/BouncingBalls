#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "main.h"
#include "Ball.h"
#include "GameHandler.h"
#include <random>
#include <iostream>

int randomGenerator(int min, int max)
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}

int main()
{
	sf::RenderWindow win{ sf::VideoMode(WINDOWX, WINDOWY), "Window" };
	GameHandler g{};

	while (win.isOpen())
	{
		sf::Event event;

		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					win.close();
			}
			else if (event.type == sf::Event::Resized) {
			
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				Ball *b{ new Ball{} };

				g.appendEntity(b);
			}
		}
		win.clear(sf::Color::Black);
		g.makeATick(win);
		win.display();
	}
	return 0;
}