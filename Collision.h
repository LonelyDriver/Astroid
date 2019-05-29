#pragma once
#include <SFML/Graphics.hpp>

namespace astro
{
	class Collision
	{
	public:
		Collision();
		~Collision();

		bool isColling(sf::Sprite &first, sf::Sprite & second);
	};

}