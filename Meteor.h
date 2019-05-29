#pragma once
#include "Enemy.h"

namespace astro
{

	class Meteor : public Enemy
	{
	public:
		Meteor(World &world, sf::Texture & tex);
		~Meteor();

		virtual void update(sf::Time deltaTime);
	};

}