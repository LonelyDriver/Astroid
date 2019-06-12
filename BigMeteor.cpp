#include "BigMeteor.h"


astro::BigMeteor::BigMeteor(World & world, sf::Texture & tex) :
	Meteor(world, tex)
{
	m_mass = 0.15;
	std::cout << "BigMeteor created\n";
}

astro::BigMeteor::~BigMeteor()
{
	std::cout << "BigMeteor destroyed\n";
}

int astro::BigMeteor::getPoints()
{
	return 100;
}

void astro::BigMeteor::update(sf::Time deltaTime)
{
	float seconds = deltaTime.asSeconds();

	m_pos += m_vel * seconds * 30.f;
	setPosition(m_pos);
}
