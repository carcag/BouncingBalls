#include "Ball.h"
#include <iostream>

int Ball::m_idGen;


/*Ball::Ball()
{
	int c_red{}, c_green{}, c_blue{};

	validColorGenerator(c_red, c_green, c_blue);

	m_shape.setRadius(20.f);
	m_shape.setFillColor(sf::Color(c_red, c_green, c_blue));
	m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius());
	m_shape.setPosition(randomGenerator(0 + m_shape.getRadius(), WINDOWX - m_shape.getRadius()), randomGenerator(0 + m_shape.getRadius(), WINDOWY - m_shape.getRadius()));
	validSpeedGenerator();
	m_collideChecked = false;
	m_type = "Ball";

	m_id = ++Ball::m_idGen;
}*/

Ball::Ball()
{
	*this = Ball(randomGenerator(0 + m_shape.getRadius(), WINDOWX - m_shape.getRadius()), randomGenerator(0 + m_shape.getRadius(), WINDOWY - m_shape.getRadius()));
}

Ball::Ball(float x, float y)
{
	int c_red{}, c_green{}, c_blue{};

	validColorGenerator(c_red, c_green, c_blue);
	*this = Ball(x, y, sf::Color(c_red, c_green, c_blue));
}

Ball::Ball(float x, float y, sf::Color color)
{
	validSpeedGenerator();
	*this = Ball(x, y, color, m_speedX, m_speedY);
}

Ball::Ball(float x, float y, sf::Color color, double speedX, double speedY)
{
	m_shape.setRadius(20.f);
	m_shape.setFillColor(color);
	m_shape.setPosition(x, y);
	m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius());
	m_collideChecked = false;
	m_type = "Ball";
	m_speedX = speedX;
	m_speedY = speedY;

	m_id = ++Ball::m_idGen;
}

Ball::~Ball()
{

}

const sf::Vector2f Ball::getPosition() const
{
	return m_shape.getPosition();
}
const std::string Ball::getType() const
{
	return m_type;
}

void Ball::setPosition(sf::Vector2f v)
{
	m_shape.setPosition(v);
}

void Ball::makeATick()
{
	float x = m_shape.getPosition().x;
	float y = m_shape.getPosition().y;

	if (m_movXSens)
	{
		if (x + m_speedX + (m_shape.getRadius()) >= WINDOWX)
		{
			m_movXSens = false;
			m_shape.setPosition(x - m_speedX, y);

		}
		else
			m_shape.setPosition(x + m_speedX, y);
	}
	else
	{
		if (x - m_shape.getRadius() - m_speedX <= 0)
		{
			m_movXSens = true;
			m_shape.setPosition(x + m_speedX, y);
		}
		else
			m_shape.setPosition(x - m_speedX, y);
	}

	x = m_shape.getPosition().x;
	y = m_shape.getPosition().y;

	if (m_movYSens)
	{
		if (y + m_speedY + (m_shape.getRadius()) >= WINDOWY)
		{
			m_movYSens = false;
			m_shape.setPosition(x, y - m_speedY);
		}
		else
			m_shape.setPosition(x, y + m_speedY);
	}
	else
	{
		if (y - m_shape.getRadius() - m_speedY <= 0)
		{
			m_movYSens = true;
			m_shape.setPosition(x, y + m_speedY);
		}
		else
			m_shape.setPosition(x, y - m_speedY);
	}
}

sf::CircleShape& Ball::getShape()
{
	return m_shape;
}

void Ball::collideX(bool dirChanged, float dirVector)
{
	if (dirChanged)
		m_movXSens = !(m_movXSens);
	m_speedX += dirVector;
}

void Ball::collideY(bool dirChanged, float dirVector)
{
	if (dirChanged)
		m_movYSens = !(m_movYSens);
	m_speedY += dirVector;

}

bool Ball::getMovXSens()
{
	return m_movXSens;
}

bool Ball::getMovYSens()
{
	return m_movYSens;
}

const float Ball::getSpeedX() const
{
	return m_speedX;
}

const float Ball::getSpeedY() const
{
	return m_speedY;
}


void Ball::setCollideChecked(bool state)
{
	m_collideChecked = state;
}

bool Ball::getCollideChecked()
{
	return m_collideChecked;
}

void Ball::validColorGenerator(int &r, int &g, int &b)
{
	do 
	{
		r = randomGenerator(0, 255);
		g = randomGenerator(0, 255);
		b = randomGenerator(0, 255);
	} while (r < 30 || g < 30 || b < 30);
}

void Ball::validSpeedGenerator()
{

	double LO{ .005 }, HI{ .1 };

	m_speedX = LO + static_cast <double> (randomGenerator(0, 100)) / (static_cast <double> (100 / (HI - LO)));
	m_speedY = LO + static_cast <double> (randomGenerator(0, 100)) / (static_cast <double> (100 / (HI - LO)));
}

void Ball::setSpeed(double speedX, double speedY)
{
	m_speedX = speedX;
	m_speedY = speedY;
}