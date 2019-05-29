#include "Entity.h"

namespace astro
{

	Entity::Entity(World & world, sf::Texture &tex) : m_world(world),
		m_pos(0, 0),
		m_vel(0, 0),
		m_alive(true)
	{
		m_sprite.setTexture(tex);
		sf::FloatRect size = m_sprite.getGlobalBounds();
		m_sprite.setOrigin(size.width / 2, size.height / 2);
	}

	Entity::~Entity()
	{
	}

	void Entity::update(sf::Time deltaTime)
	{
	}

	void Entity::processEvents()
	{
	}

	const sf::Vector2f & Entity::getPosition()
	{
		return m_sprite.getPosition();
	}

	void Entity::setPosition(sf::Vector2f pos)
	{
		m_sprite.setPosition(pos);
		m_pos = pos;
	}

	bool Entity::isAlive() const
	{
		return m_alive;
	}

	void Entity::onDestroy()
	{
		m_alive = false;
	}

	sf::Sprite & Entity::getSprite()
	{
		return m_sprite;
	}

	void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(m_sprite, states);
	}

}