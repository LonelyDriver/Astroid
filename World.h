#pragma once
#include <list>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Collision.h"

namespace astro
{

	class World : public sf::Drawable
	{
	public:
		World(int x, int y);
		~World();

		void add(Entity * entity);
		void update(sf::Time deltaTime);
		void processEvents();
		void clear();
		int getSize() const;
		bool gameOver() const;

	private:
		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

		int m_Y, m_X;
		int m_lives;
		int m_score;
		float m_collisionT;
		std::list<Entity*> m_entities;
		Collision m_collision;
	};

}