#include "Player.h"


namespace astro
{


	Player::Player(World &world, sf::Texture &tex) : Entity(world, tex),
		m_rotation(0),
		m_isMoving(false)
	{
		m_mass = .15;
		m_sprite.setPosition(sf::Vector2f(300, 300));
		std::cout << "Player created\n";
	}

	Player::~Player()
	{
		std::cout << "Player destroyed\n";
	}

	void Player::update(sf::Time deltaTime)
	{
		float seconds = deltaTime.asSeconds();

		if (m_rotation != 0)
		{
			float angle = m_rotation * 180.f * seconds;
			m_sprite.rotate(angle);
		}

		if (m_isMoving)
		{
			float angle = m_sprite.getRotation() / 180 * PI - PI / 2;

			m_vel += sf::Vector2f(std::cos(angle), std::sin(angle)) * seconds;

			if (m_vel.x > 1.f)
				m_vel.x = 1.f;
			else if (m_vel.x < -1.f)
				m_vel.x = -1.f;

			if (m_vel.y > 1.f)
				m_vel.y = 1.f;
			else if (m_vel.y < -1.f)
				m_vel.y = -1.f;
		}

		m_pos += m_vel * seconds * 300.f;

		m_sprite.setPosition(m_pos);
	}

	void Player::processEvents()
	{
		m_rotation = 0;
		m_rotation -= sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		m_rotation += sf::Keyboard::isKeyPressed(sf::Keyboard::D);

		m_isMoving = false;
		m_isMoving = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	}


}