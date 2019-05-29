#include "Meteor.h"

astro::Meteor::Meteor(World & world, sf::Texture & tex) :
	Enemy(world, tex)
{
}

astro::Meteor::~Meteor()
{
}

void astro::Meteor::update(sf::Time deltaTime)
{
	float seconds = deltaTime.asSeconds();

	m_pos += m_vel * seconds * 60.f;
	setPosition(m_pos);
}
