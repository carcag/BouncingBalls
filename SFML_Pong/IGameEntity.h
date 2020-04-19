#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class IGameEntity
{
public:
	int m_id;

	virtual const sf::Vector2f getPosition() const = 0;
	virtual const std::string getType() const = 0;
	virtual void setPosition(sf::Vector2f v) = 0;
	virtual void makeATick() = 0;
	virtual sf::Shape& getShape() = 0;
	virtual bool getMovXSens() = 0;
	virtual bool getMovYSens() = 0;
	virtual void collideX(bool dirChanged, float dirVector = 0.f) = 0;
	virtual void collideY(bool dirChanged, float dirVector = 0.f) = 0;
	virtual const float getSpeedX() const = 0;	
	virtual const float getSpeedY() const = 0;
	virtual void setCollideChecked(bool state) = 0;
	virtual bool getCollideChecked() = 0;


protected:
	std::string m_type;
	bool m_collideChecked;
};