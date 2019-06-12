#pragma once
#include "Meteor.h"

namespace astro
{

	class MedMeteor : public Meteor
	{
	public:
		MedMeteor(World &world, sf::Texture &tex);
		~MedMeteor();

		int getPoints();
		void update(sf::Time deltaTime);
	};

}