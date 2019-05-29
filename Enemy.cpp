#include "Enemy.h"


astro::Enemy::Enemy(World & world, sf::Texture & tex) : Entity(world, tex)
{
	float angle = random(0,2*PI);
	m_vel = sf::Vector2f(std::cos(angle), std::sin(angle));
}

astro::Enemy::~Enemy()
{
}

int astro::Enemy::getPoints()
{
	return 10;
}

