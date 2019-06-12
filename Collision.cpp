#include "Collision.h"



astro::Collision::Collision()
{
}


astro::Collision::~Collision()
{
}

bool astro::Collision::isColliding(sf::Sprite & first, sf::Sprite & second)
{
	sf::FloatRect size1 = first.getGlobalBounds();
	sf::FloatRect size2 = second.getGlobalBounds();

	float radius1 = size1.width / 2;
	float radius2 = size2.width / 2;

	float a = second.getPosition().x - first.getPosition().x;
	float b = second.getPosition().y - first.getPosition().y;

	return std::sqrt(a*a + b*b) <= (radius1 + radius2);
}

void astro::Collision::elasticCollision(Entity * pFirst, Entity * pSecond)
{
	float m1 = pFirst->getMass();
	float m2 = pSecond->getMass();
	sf::Vector2f v1 = pFirst->getVelocity();
	sf::Vector2f v2 = pSecond->getVelocity();
	sf::Vector2f x1 = pFirst->getPosition();
	sf::Vector2f x2 = pSecond->getPosition();
	sf::Vector2f tmp1, tmp2;

	if (m1 == m2)
	{
		pFirst->setVelocity(v2);
		pSecond->setVelocity(v1);
		return;
	}

	float term11 = 2 * m2 / (m1 + m2);
	tmp1 = this->vecSub(v1, v2);
	tmp2 = this->vecSub(x1, x2);

	//float term112 = this->vecDot(this->vecSub(v1, v2), this->vecSub(x1, x2));
	float term12 = this->vecDot(tmp1, tmp2);
	float term13 = this->vecMagnitude(tmp2) * this->vecMagnitude(tmp2);
	sf::Vector2f x11 = vecSub(x1, x2);
	x11.x *= (term11 * term12 / term13);
	x11.y *= (term11 * term12 / term13);

	pFirst->setVelocity(vecSub(v1, x11));
	

	float term21 = 2 * m1 / (m1 + m2);
	tmp1 = this->vecSub(v2, v1);
	tmp2 = this->vecSub(x2, x1);

	double term22 = this->vecDot(tmp1, tmp2);
	double term23 = this->vecMagnitude(tmp2) * this->vecMagnitude(tmp2);
	sf::Vector2f x21 = vecSub(x2, x1);
	x21.x *= (term11 * term12 / term13);
	x21.y *= (term11 * term12 / term13);

	pSecond->setVelocity(vecSub(v2, x21));

	if (x1.x < x2.x)
	{
		x1.x -= 5.;
	}
	else
	{
		x1.x += 5.;
	}

	if (x1.y < x2.y)
	{
		x1.y -= 5.;
	}
	else
	{
		x1.y += 5.;
	}
	pFirst->setPosition(x1);
}

sf::Vector2f & astro::Collision::vecSub(sf::Vector2f & vec1, sf::Vector2f & vec2)
{
	sf::Vector2f result(vec1.x - vec2.x, vec1.y - vec2.y);
	return result;
}

sf::Vector2f & astro::Collision::vecAdd(sf::Vector2f & vec1, sf::Vector2f & vec2)
{
	sf::Vector2f result(vec1.x + vec2.x, vec1.y + vec2.y);
	return result;
}

float astro::Collision::vecMagnitude(sf::Vector2f & vec1)
{
	float result = std::sqrt(vec1.x*vec1.x + vec1.y*vec1.y);
	return result;
}

float astro::Collision::vecDot(sf::Vector2f & vec1, sf::Vector2f & vec2)
{
	float result= vec1.x*vec2.x + vec1.y*vec2.y;
	return result;
}
