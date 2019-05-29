#pragma once
#include "ResourceManager.h"
#include "random.h"

namespace astro
{
	class Manager
	{
	public:
		Manager() = delete;
		Manager(const Manager&) = delete;
		Manager& operator=(const Manager&) = delete;

		static ResourceManager resources;

		enum Textures : int {Player=0,
							 Background,
							 BigMeteor1,
							 BigMeteor2,
							 BigMeteor3,
							 BigMeteor4,
							 MedMeteor1,
							 MedMeteor2,
							 SmallMeteor1,
							 SmallMeteor2,
							 Enemy1,
							 Enemy2,
							 LaserPlayer,
							 LaserEnemy,
							 PlayerLife,
							 };
		enum Fonts : int {Font=0};

		static void initialize();
	};

}