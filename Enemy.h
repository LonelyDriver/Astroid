#pragma once
#include "Entity.h"
#include "random.h"

namespace astro
{
	class World;

	class Enemy : public Entity
	{
	public:
		Enemy(World &world, sf::Texture &tex);
		~Enemy();

		virtual int getPoints();

	};

}