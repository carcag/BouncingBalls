#pragma once

#include "main.h"
#include "IGameEntity.h"

class Ball: public IGameEntity
{
public:
	
	Ball();
	Ball(float x, float y);
	Ball(float x, float y, sf::Color color);
	Ball(float x, float y, sf::Color color, double speed, double speedY);
	~Ball();


	virtual const sf::Vector2f getPosition() const;
	virtual const std::string getType() const;
	virtual void setPosition(sf::Vector2f v);
	virtual void makeATick();
	virtual sf::CircleShape& getShape();
	virtual void collideX(bool dirChanged, float dirVector = 0.f);
	virtual void collideY(bool dirChanged, float dirVector = 0.f);
	virtual bool getMovXSens();
	virtual bool getMovYSens();
	virtual const float getSpeedX() const;
	virtual const float getSpeedY() const;
	virtual void setCollideChecked(bool state);
	virtual bool getCollideChecked();
	virtual void validColorGenerator(int &r, int &g, int &b);
	virtual void validSpeedGenerator();
	virtual void setSpeed(double speedX, double speedY);

private:
	sf::CircleShape m_shape;
	bool m_movXSens, m_movYSens;
	float m_speedX;
	float m_speedY;
	sf::Vector2f m_origin;
	static int m_idGen;
};

