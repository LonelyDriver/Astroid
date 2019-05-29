#include "World.h"

namespace astro
{

	World::World(int x, int y) : 
		m_X(x),
		m_Y(y),
		m_lives(3),
		m_score(0),
		m_collision(),
		m_collisionT(0)
	{
		std::cout << "World created!\n";
	}

	World::~World()
	{
		clear();
		std::cout << "World destroyed!\n";
	}

	void World::add(Entity * entity)
	{
		m_entities.push_back(entity);
	}

	void World::update(sf::Time deltaTime)
	{
		m_collisionT += deltaTime.asSeconds();

		if (m_entities.size() > 0)
		{
			
			for (Entity *entity_ptr : m_entities)
			{

				entity_ptr->update(deltaTime);

				sf::Vector2f pos = entity_ptr->getPosition();
				
				// check world boundaries
				if (pos.x > m_X)
					pos = sf::Vector2f(0, m_Y - pos.y);
				else if (pos.x < 0)
					pos = sf::Vector2f(m_X, m_Y - pos.y);

				if (pos.y > m_Y)
					pos = sf::Vector2f(m_X - pos.x, 0);
				else if (pos.y < 0)
					pos = sf::Vector2f(m_X - pos.x, m_Y);

				entity_ptr->setPosition(pos);
			}

			// Collision detection, invincible for 3 seconds after collision
			std::list<Entity*>::iterator it;
			it = m_entities.begin();
			Entity * pFirst = *it;

			for (it = std::next(m_entities.begin()); it != m_entities.end(); ++it)
			{
				Entity *pSecond = *it;
				if (m_collision.isColling(pFirst->getSprite(), pSecond->getSprite()) && m_collisionT >= 3.f)
				{
					m_collisionT = 0;
					--m_lives;
				}				
			}

		}
		else
			std::cout << "Empty World!\n";

	}

	void World::processEvents()
	{
		if (m_entities.size() > 0)
		{
			for (Entity *entity : m_entities)
			{
				entity->processEvents();
			}
		}
	}

	void World::clear()
	{
		for (Entity *entity : m_entities)
		{
			delete entity;
		}
		m_entities.clear();
	}

	int World::getSize() const
	{
		return m_entities.size();
	}

	bool World::gameOver() const
	{
		if(m_lives <= 0)
			return true;
		return false;
	}

	void World::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		for (Entity * entity : m_entities)
		{
			target.draw(*entity);
		}
	}

}