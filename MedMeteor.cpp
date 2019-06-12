#include "MedMeteor.h"


astro::MedMeteor::MedMeteor(World & world, sf::Texture & tex) : Meteor(world, tex)
{
	m_mass = .15;
	std::cout << "BigMeteor created\n";
}

astro::MedMeteor::~MedMeteor()
{
	std::cout << "BigMeteor destroyed\n";
}

int astro::MedMeteor::getPoints()
{
	return 70;
}

void astro::MedMeteor::update(sf::Time deltaTime)
{
	float seconds = deltaTime.asSeconds();

	m_pos += m_vel * seconds * 60.f;
	setPosition(m_pos);
}
