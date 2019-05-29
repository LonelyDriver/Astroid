#include "Game.h"

namespace astro
{

	Game::Game(int x, int y) :
		m_window(sf::VideoMode(x, y), "Astroids v0.1"),
		m_world(x, y),
		m_running(false),
		timePerFrame(sf::seconds(1.f / 60.f)),
		m_X(x),
		m_Y(y)
	{
		Manager::initialize();

		sf::Texture &tex = Manager::resources.getTexture(Manager::Textures::Player);
		m_player = new Player(m_world, tex);
		m_player->setPosition(sf::Vector2f(300,300));

		sf::Texture &backgrd = Manager::resources.getTexture(Manager::Textures::Background);
		m_background.setTexture(backgrd);
		sf::FloatRect size = m_background.getGlobalBounds();
		m_background.setScale(x / size.width, y / size.height);

		init(6);

		sf::Font &font = Manager::resources.getFont(Manager::Fonts::Font);
		m_text.setFont(font);
		m_text.setCharacterSize(70);

		std::cout << "Game created!\n";
	}

	Game::~Game()
	{
		std::cout << "Game destroyed!\n";
	}

	void Game::run()
	{
		m_running = true;
		sf::Clock clock;
		sf::Time timeSinceLastUpdate;

		while (isrunning())
		{
			processEvents();
			timeSinceLastUpdate = clock.restart();

			while (timeSinceLastUpdate >= timePerFrame)
			{
				timeSinceLastUpdate -= timePerFrame;
				update(timePerFrame);
			}
			update(timeSinceLastUpdate);
			render();
		}
	}

	bool Game::isrunning() const
	{
		return m_running;
	}

	void Game::init(int nb_meteors)
	{
		m_world.clear();
		m_world.add(m_player);
		int nb_med_meteors = nb_meteors - 2;
		
		for (int i = 0; i < nb_meteors; ++i)
		{
			sf::Texture &tex = Manager::resources.getTexture(random(Manager::Textures::BigMeteor1, Manager::Textures::BigMeteor4));
			Meteor *p_meteor = new BigMeteor(m_world, tex);
			p_meteor->setPosition(sf::Vector2f(random(1, m_X), random(1, m_Y)));
			m_world.add(p_meteor);
		}
		for (int ii = 0; ii < nb_med_meteors; ++ii)
		{
			sf::Texture &tex = Manager::resources.getTexture(random(Manager::Textures::MedMeteor1, Manager::Textures::MedMeteor2));
			Meteor *p_meteor = new MedMeteor(m_world, tex);
			p_meteor->setPosition(sf::Vector2f(random(1, m_X), random(1, m_Y)));
			m_world.add(p_meteor);
		}


		std::cout << "World Size: " << m_world.getSize() << std::endl;
	}

	void Game::reset()
	{
		m_player->setPosition(sf::Vector2f(300, 300));

	}

	void Game::processEvents()
	{
		sf::Event evnt;
		while (m_window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed || evnt.key.code == sf::Keyboard::Escape)
			{
				m_window.close();
				m_running = false;
			}

			if (m_world.gameOver())
			{
				if (evnt.key.code == sf::Keyboard::P)
					init(6);
			}
			else
				m_world.processEvents();
		}

		
		
	}

	void Game::update(sf::Time deltaTime)
	{
		if(!m_world.gameOver())
			m_world.update(deltaTime);
		else
			std::cout << "GameOver!\n";
	}

	void Game::render()
	{
		m_window.clear();
		if (!m_world.gameOver())
		{
			m_window.draw(m_background);
			m_window.draw(m_world);
		}
		
		m_window.display();
	}

}