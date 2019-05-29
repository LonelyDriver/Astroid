#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace astro
{

	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

		void loadTexture(int idx, std::string file);
		sf::Texture & getTexture(int idx);

		void loadFont(int idx, std::string file);
		sf::Font & getFont(int idx);

	private:
		std::map<int, sf::Texture> m_map;
		std::map<int, sf::Font> m_FontMap;
	};

}