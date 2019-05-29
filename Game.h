#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "World.h"
#include "Player.h"
#include "Manager.h"
#include "BigMeteor.h"
#include "MedMeteor.h"
#include "random.h"

namespace astro
{

	class Game
	{
	public:
		Game(int x = 1080, int y = 720);
		~Game();

		void run();
		bool isrunning() const;
		void init(int nb_meteors);
		void reset();

		void processEvents();
		void update(sf::Time deltaTime);
		void render();


	private:
		bool m_running;
		sf::RenderWindow m_window;
		World m_world;
		sf::Time timePerFrame;
		Player *m_player;
		sf::Sprite m_background;
		sf::Text m_text;
		int m_X, m_Y;
	};

}