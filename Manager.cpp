#include "Manager.h"

namespace astro
{

	ResourceManager Manager::resources;


	void Manager::initialize()
	{
		resources.loadTexture(Manager::Textures::Player, "assets/PNG/playerShip2_red.png");
		resources.loadTexture(Manager::Textures::Background, "assets/Backgrounds/darkPurple.png");
		resources.loadTexture(Manager::Textures::BigMeteor1, "assets/PNG/Meteors/meteorBrown_big1.png");
		resources.loadTexture(Manager::Textures::BigMeteor2, "assets/PNG/Meteors/meteorBrown_big2.png");
		resources.loadTexture(Manager::Textures::BigMeteor3, "assets/PNG/Meteors/meteorBrown_big3.png");
		resources.loadTexture(Manager::Textures::BigMeteor4, "assets/PNG/Meteors/meteorBrown_big4.png");
		resources.loadTexture(Manager::Textures::MedMeteor1, "assets/PNG/Meteors/meteorBrown_med1.png");
		resources.loadTexture(Manager::Textures::MedMeteor2, "assets/PNG/Meteors/meteorBrown_med3.png");
		resources.loadTexture(Manager::Textures::SmallMeteor1, "assets/PNG/Meteors/meteorBrown_small1.png");
		resources.loadTexture(Manager::Textures::SmallMeteor2, "assets/PNG/Meteors/meteorBrown_small2.png");
		resources.loadTexture(Manager::Textures::Enemy1, "assets/PNG/Enemies/enemyBlack1.png");
		resources.loadTexture(Manager::Textures::Enemy2, "assets/PNG/Enemies/enemyBlack2.png");
		resources.loadTexture(Manager::Textures::LaserPlayer, "assets/PNG/Lasers/laserRed12.png");
		resources.loadTexture(Manager::Textures::LaserEnemy, "assets/PNG/Lasers/laserBlue03.png");
		resources.loadTexture(Manager::Textures::PlayerLife, "assets/PNG/UI/playerShip2_red.png");

		resources.loadFont(Manager::Fonts::Font, "assets/Bonus/kenvector_future.ttf");

	}



}