#include "Collision.h"



astro::Collision::Collision()
{
}


astro::Collision::~Collision()
{
}

bool astro::Collision::isColling(sf::Sprite & first, sf::Sprite & second)
{
	sf::FloatRect size1 = first.getGlobalBounds();
	sf::FloatRect size2 = second.getGlobalBounds();

	float radius1 = size1.width / 2;
	float radius2 = size2.width / 2;

	float a = second.getPosition().x - first.getPosition().x;
	float b = second.getPosition().y - first.getPosition().y;

	return std::sqrt(a*a + b*b) <= (radius1 + radius2);
}
