#include "GameHandler.h"


GameHandler::GameHandler()
{
}

GameHandler::~GameHandler()
{
	for (auto *elem : m_entities)
		delete elem;
}

void GameHandler::resetCollide()
{
	for (auto *entity : m_entities)
	{
		entity->setCollideChecked(false);
	}
}

void GameHandler::makeATick(sf::RenderWindow &win)
{
	for (auto *entity : m_entities)
	{
		collideCheck(entity);
		entity->makeATick();
		win.draw(entity->getShape());
	}
	resetCollide();
}

void GameHandler::appendEntity(IGameEntity *entity)
{
	m_entities.push_back(entity);
}

void GameHandler::collideCheck(IGameEntity *entity)
{
	if (!(entity->getCollideChecked()))
	{
		for (auto *entityChecked : m_entities)
		{
			if (entity == entityChecked)
			{
				continue;
			}
			
			float xDistance{ dynamic_cast<Ball*>(entity)->getShape().getPosition().x - dynamic_cast<Ball*>(entityChecked)->getShape().getPosition().x };
			float yDistance{ dynamic_cast<Ball*>(entity)->getShape().getPosition().y - dynamic_cast<Ball*>(entityChecked)->getShape().getPosition().y };
			float cumuledRadius{ (dynamic_cast<Ball*>(entity)->getShape().getRadius() + dynamic_cast<Ball*>(entity)->getShape().getRadius())};

			if (sqrt(xDistance * xDistance + yDistance * yDistance) <= cumuledRadius)
			{
				float speedXDiff{ entity->getSpeedX() - entityChecked->getSpeedX() };
				float speedYDiff{ entity->getSpeedY() - entityChecked->getSpeedY() };

				if (entity->getMovXSens() != entityChecked->getMovXSens())
				{
					entity->collideX(true, -speedXDiff);
					entityChecked->collideX(true, speedXDiff);
				}
				else
				{
					entity->collideX(false, -speedXDiff);
					entityChecked->collideX(false, speedXDiff);
				}

				if (entity->getMovYSens() != entityChecked->getMovYSens())
				{
					entity->collideY(true, -speedYDiff);
					entityChecked->collideY(true, speedYDiff);
				}
				else
				{
					entity->collideY(false, -speedYDiff);
					entityChecked->collideY(false, speedYDiff);
				}

				entity->setCollideChecked(true);
				entityChecked->setCollideChecked(true);
			}
		}
	}
}