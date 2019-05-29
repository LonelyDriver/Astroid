#pragma once
#include "Meteor.h"

namespace astro
{
	class BigMeteor : public Meteor
	{
	public:
		BigMeteor(World &world, sf::Texture &tex);
		~BigMeteor();

		int getPoints();
		void update(sf::Time deltaTime);
	};

}