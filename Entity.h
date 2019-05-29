#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#define PI 3.14159265359

namespace astro
{
	class World;

	class Entity : public sf::Drawable
	{
	public:
		Entity(World & world, sf::Texture &tex);
		~Entity();

		virtual void update(sf::Time deltaTime);
		virtual void processEvents();
		const sf::Vector2f& getPosition();
		virtual void setPosition(sf::Vector2f pos);
		bool isAlive() const;
		virtual void onDestroy();
		sf::Sprite & getSprite();

	protected:

		sf::Sprite m_sprite;
		World & m_world;
		sf::Vector2f m_pos;
		sf::Vector2f m_vel;
		bool m_alive;
	private:
		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	};

}
