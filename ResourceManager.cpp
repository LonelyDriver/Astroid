#include "ResourceManager.h"

namespace astro
{

	ResourceManager::ResourceManager()
	{
		std::cout << "ResourceManager created\n";
	}


	ResourceManager::~ResourceManager()
	{
		std::cout << "ResourceManager destroyed\n";
	}

	void ResourceManager::loadTexture(int idx, std::string file)
	{
		sf::Texture tex;
		if (!tex.loadFromFile(file))
			std::cout << "Cant load file\n";
		m_map[idx] = tex;
	}

	sf::Texture & ResourceManager::getTexture(int idx)
	{
		return m_map.at(idx);
	}

	void ResourceManager::loadFont(int idx, std::string file)
	{
		sf::Font font;
		if (!font.loadFromFile(file))
			std::cout << "Cant load file\n";
		m_FontMap[idx] = font;
	}

	sf::Font & ResourceManager::getFont(int idx)
	{
		return m_FontMap.at(idx);
	}

}