#pragma once

#include <vector>
#include <iostream>
#include <cmath>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "IGameEntity.h"
#include "Ball.h"

class GameHandler
{
public:
	GameHandler();
	~GameHandler();

	void makeATick(sf::RenderWindow &win);
	void appendEntity(IGameEntity *entity);
	void resetCollide();

private:
	std::vector<IGameEntity*> m_entities;

	void collideCheck(IGameEntity *entity);
};
