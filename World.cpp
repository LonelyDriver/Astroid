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

			// check collision with each entity
			std::list<Entity*> list_copiedEntities(std::next(m_entities.begin()), m_entities.end());

			for (it; it != m_entities.end(); ++it)
			{
				Entity *pFirst = *it;
				std::list<Entity*>::iterator jt;
				for (jt = list_copiedEntities.begin(); jt != list_copiedEntities.end(); ++jt)
				{
					Entity *pSecond = *jt;
					bool collide = m_collision.isColliding(pFirst->getSprite(), pSecond->getSprite());
					if (collide)
					{
						m_collision.elasticCollision(pFirst, pSecond);
					}
						
				}
				list_copiedEntities.pop_front();
				if (list_copiedEntities.size() < 1)
					break;
			}


			/*for (it = std::next(m_entities.begin()); it != m_entities.end(); ++it)
			{
				Entity *pSecond = *it;
				if (m_collision.isColling(pFirst->getSprite(), pSecond->getSprite()) && m_collisionT >= 3.f)
				{
					m_collisionT = 0;
					--m_lives;
				}				
			}*/

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