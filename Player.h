#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>


namespace astro
{

	class Player : public Entity
	{
	public:
		Player(World &world, sf::Texture &tex);
		~Player();

		void update(sf::Time deltaTime);
		void processEvents();

	private:
		int m_rotation;
		bool m_isMoving;

	};

}