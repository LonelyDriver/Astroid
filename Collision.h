#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace astro
{
	class Collision
	{
	public:
		Collision();
		~Collision();

		bool isColliding(sf::Sprite &first, sf::Sprite & second);
		void elasticCollision(Entity *pFirst, Entity *pSecond);
		sf::Vector2f& vecSub(sf::Vector2f& vec1, sf::Vector2f & vec2);
		sf::Vector2f& vecAdd(sf::Vector2f& vec1, sf::Vector2f & vec2);
		float vecMagnitude(sf::Vector2f& vec1);
		float vecDot(sf::Vector2f& vec1, sf::Vector2f & vec2);
	};

}